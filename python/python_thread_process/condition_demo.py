import time
from threading import Thread, RLock, Condition, current_thread


def func1(c):
    c.acquire(False)  # 固定格式
    # print(1111)

    c.wait()  # 等待通知,
    time.sleep(1)  # 通知完成后大家是串行执行的，这也看出了锁的机制了
    print('%s执行了' % (current_thread().getName()))

    c.release()


if __name__ == '__main__':
    c = Condition()
    for i in range(5):
        t = Thread(target=func1, args=(c,))
        t.start()

    while True:
        num = int(input('请输入你要通知的线程个数:'))
        c.acquire()  # 固定格式
        c.notify(num)  # 通知num个线程别等待了，去执行吧
        c.release()
