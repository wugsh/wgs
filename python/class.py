#!/usr/bin/env python
# coding=utf-8

__metaclass_ = type

class Person:

    def setName(self, name):
        self.name = name
    
    def getName(self):
        return self.name

    def greet(self):
        print "Hello, world! I'm %s." % self.name
