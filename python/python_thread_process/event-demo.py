from threading import Thread, Event
import threading
import time
import random


def conn_mysql():
    count = 1
    while not event.is_set():
        if count > 3:
            raise TimeoutError('链接超时')
        print('<%s>第%s次尝试链接' % (threading.current_thread().getName(), count))
        event.wait(0.5)
        count += 1
    print('<%s>链接成功' % threading.current_thread().getName())


def check_mysql():
    print('正在检查mysql' % threading.current_thread().getName())
    t1 = random.randint(0, 3)
    print('>>>>', t1)
    time.sleep(t1)
    event.set()


if __name__ == '__main__':
    event = Event()
    check = Thread(target=check_mysql)
    conn1 = Thread(target=conn_mysql)
    conn2 = Thread(target=conn_mysql)

    check.start()
    conn1.start()
    conn2.start()
