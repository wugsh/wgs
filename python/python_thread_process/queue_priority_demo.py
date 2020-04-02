import queue

q = queue.PriorityQueue()
# put进入一个元组,元组的第一个元素是优先级(通常是数字,也可以是非数字之间的比较),数字越小优先级越高
q.put((-10, 'a'))
q.put((-5, 'a'))  # 负数也可以
# q.put((20,'ws'))  #如果两个值的优先级一样，那么按照后面的值的acsii码顺序来排序,如果字符串第一个数元素相同，比较第二个元素的acsii码顺序
# q.put((20,'wd'))
# q.put((20,{'a':11})) #TypeError: unorderable types: dict() < dict() 不能是字典
# q.put((20,('w',1)))  #优先级相同的两个数据，他们后面的值必须是相同的数据类型才能比较，可以是元祖，也是通过元素的ascii码顺序来排序

q.put((20, 'b'))
q.put((20, 'a'))
q.put((0, 'b'))
q.put((30, 'c'))

print(q.get())
print(q.get())
print(q.get())
print(q.get())
print(q.get())
print(q.get())
