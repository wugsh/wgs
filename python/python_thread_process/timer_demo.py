import time
from threading import Timer, current_thread  # 这里就不需要再引入Timer
import threading


def hello():
    print(current_thread().getName())
    print("hello, world")

    # time.sleep(3) #如果你的子线程的程序执行时间比较长，那么这个定时任务也会乱，当然了，主要还是看业务需求
t = Timer(1, hello)  # 创建一个子线程去执行后面的函数
t.start()  # after 1 seconds, "hello, world" will be printed
# for i in range(5):
#     t = Timer(2, hello)
#     t.start()
#     time.sleep(3) #这个是创建一个t用的时间是2秒，创建出来第二个的时候，第一个已经过了两秒了，所以你的5个t的执行结果基本上就是2秒中，这个延迟操作。

print(threading.active_count())
print('主进程', current_thread().getName())
