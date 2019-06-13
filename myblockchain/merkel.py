# coding=utf-8
import math
import random
import hashlib
class Node:
    def __init__(self,item):
        self.item = item
        self.child1 = None
        self.child2 = None
        self.hash = None
        self.data = None
    def change_data(self,data):
        self.data=data
        self.hash = hashlib.md5(data.encode('utf-8')).hexdigest()[8:-8] #hexdigest()返回摘要，作为十六进制数据字符串值 [8:-8]将32位MD5转换为16进制
        print("make_hash",self.hash,"size",len(self.hash),end=" ")
        return self.hash
:
    def __init__(self):
        self.root = None
class Tree
    def add(self, item):#逐层添加子节点
        node = Node(item)
        end_str = make_data(item)
        print("add node ",item)
        if end_str !=None and end_str != -1:
            node.change_data(end_str)
            print("data= %s " % (node.data))
            print("hash= %s " % (node.hash))
        if self.root is None:
            self.root = node
        else:
            q = [self.root]
            while True:
                pop_node = q.pop(0)
                if pop_node.child1 is None:
                    pop_node.child1 = node
                    return
                elif pop_node.child2 is None:
                    pop_node.child2 = node
                    return
                else:
                    q.append(pop_node.child1)
                    q.append(pop_node.child2)

    def reload_hash(self):  # 层次遍历更新hash
        if self.root is None:
            return None
        q = [self.root]
        item = [(self.root.item,self.root.data,self.root.hash)]
        while q != []:
            pop_node = q.pop(0)
            if pop_node.child1 and pop_node.child2 :
                if pop_node.child1.hash and pop_node.child2.hash:
                    print("更新基础节点",pop_node.item,end=" ")
                    end_str=pop_node.child1.hash+pop_node.child2.hash
                    end_hash=pop_node.change_data(end_str)
                    print("end_hash= %s " % (end_hash))

            if pop_node.child1 is not None:
                q.append(pop_node.child1)

            if pop_node.child2 is not None:
                q.append(pop_node.child2)
        return
    def traverse(self):  # 层次遍历
        if self.root is None:
            return None
        q = [self.root]
        item = [(self.root.item,self.root.data,self.root.hash)]
        while q != []:
            pop_node = q.pop(0)
            if pop_node.child1 is not None:
                q.append(pop_node.child1)
                item.append((pop_node.child1.item,pop_node.child1.data,pop_node.child1.hash))

            if pop_node.child2 is not None:
                q.append(pop_node.child2)
                item.append((pop_node.child2.item,pop_node.child2.data,pop_node.child2.hash))

        return (item)

def make_data(i):
    if i>6 and i<15:
        raw_str = "xizzhongcai15310120233"
        nums = math.floor(1e5 * random.random())
        nums = str(nums)
        nums = nums.zfill(5)
        end_str = raw_str + nums
        print("end_str",end_str)
        return end_str
    elif i>=0 and i<7:
        return None
    else:
        return -1

# t = Tree()
# for i in range(15):
#     t.add(i)
if __name__ == '__main__':
    t = Tree()
    for i in range(7):  # 基础节点
        t.add(i)

    for i in range(7, 15):  # 带数据的节点
        t.add(i)
    for i in range(4,0,-1): #刷新基础节点hash值
        print("第",i,'层节点hash刷新:')
        print(t.reload_hash())

print('前序遍历:\n节点名:数据：hash值',t.traverse())