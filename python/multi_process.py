import multiprocessing 
import time


def run(num):
    while  True:
        print("进程编号，%s" % num)
        time.sleep(1)


if __name__ ==  "__main__":
    for i in range(65535):
       p = multiprocessing.Process(target=run, args=(i,))
       p.start()
