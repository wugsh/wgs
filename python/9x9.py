#!/usr/bin/env python
# coding=utf-8

class PrintTable(object):
    def __init__(self):
        print('乘法口诀：\n')
        self.print99()

    def print99(self):
        for i in range(1, 10):
            for j in range(1, i+1):
                print('%dx%d = %2s  ' %(j, i, i*j)),
            print('\n')

if __name__ == '__main__':
    pt = PrintTable()

