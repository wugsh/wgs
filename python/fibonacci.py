#!/usr/bin/env python
# coding=utf-8

class Fibonacci(object):
    def __init__(self):
        self.fList = [0, 1]
        self.main()

    def main(self):
        listLen = raw_input('请输入fibonacci 数列的长度（3-50）：')
        self.checkLen(listLen)
        while len(self.fList) < int(listLen):
            self.fList.append(self.fList[-1] + self.fList[-2])
        print('得到的Fibonacci 数列为：\n %s ' %self.fList)

    def checkLen(self, lenth):
        lenList = map(str, range(3,51))
        if lenth in lenList:
            print(u'输入的长度符合标准，继续运行')
        else:
            print(u'只能输入3-50')
            exit()

if __name__ == '__main__':
    f = Fibonacci()
