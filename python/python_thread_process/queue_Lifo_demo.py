import queue

q=queue.LifoQueue() #队列，类似于栈，栈我们提过吗，是不是先进后出的顺序啊
q.put('first')
q.put('second')
q.put('third')
# q.put_nowait()

print(q.get())
print(q.get())
print(q.get())