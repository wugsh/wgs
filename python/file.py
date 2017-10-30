#!/usr/bin/env python
# coding=utf-8

f = open ('2', 'r+')
m = open ('22', 'a')
f.write ('\njfkdakfdkjfdasf&&&&&&&&&&&&&&&&&&&&&&&&')
msg = f.read(10)
while (len(msg)):
    m.write(msg)
    msg = f.read(10)

for line in f:
    print (line, end = '')

f.close()
m.close()
