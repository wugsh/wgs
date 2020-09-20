'''
一个多线程的题：定义三个线程ID分别为ABC，每个线程打印10遍自己的线程ID，
按ABCABC……的顺序进行打印输出。
'''

from threading import Thread, Lock


# 由_acquire解锁执行后释放_release锁
def _print(_id: str, _acquire: Lock, _release: Lock) -> None:
    for i in range(10):
        _acquire.acquire()
        print(f"{_id}")
        _release.release()


if __name__ == '__main__':
    # 创建三个锁供3个线程使用
    mutex1 = Lock()
    mutex2 = Lock()
    mutex3 = Lock()
    # 定义三个线程A、B、C
    # 线程A需要mutex1解锁执行后释放mutex2
    # 线程B需要mutex2解锁执行后释放mutex3
    # 线程C需要mutex3解锁执行后释放mutex1
    # 元组中第一位是自定义的线程ID，第二位是解锁需要的锁，第三位是释放的锁
    threads = [Thread(target=_print, args=[i[0], i[1], i[2]]) for i in
               [('A', mutex1, mutex2), ('B', mutex2, mutex3), ('C', mutex3, mutex1)]]
    # 把mutex2和mutex3这两把锁先用了以便阻塞线程2和线程3的执行
    mutex2.acquire()
    mutex3.acquire()
    # 接下来只有线程A可以先执行是因为mutex1并没有被占用
    # 线程B和线程C需要分别等待着锁2和锁3的释放才能继续执行
    [thr.start() for thr in threads]
    [thr.join() for thr in threads]
