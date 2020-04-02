from threading import Thread
import queue  # 不需要通过threading模块里面导入，直接import queue就可以了，这是python自带的
# 用法基本和我们进程multiprocess中的queue是一样的
import time
import random


'''
q = queue.Queue(2)
q.put('first')
q.put('second')
q.put('third')
# q.put_nowait() #没有数据就报错，可以通过try来搞
print(q.get())
print(q.get())
print(q.get())
# q.get_nowait() #没有数据就报错，可以通过try来搞
'''

def put():
    while True:
        i = random.randint(0, 100)
        s = str(i)
        q.put(s)
        time.sleep(1)


def get():
    while True:
        num = q.get()
        print(num)


if __name__ == '__main__':
    q = queue.Queue(2)
    thread_put = Thread(target=put)
    thread_get = Thread(target=get)
    thread_put.start()
    thread_get.start()
