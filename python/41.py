#!/usr/bin/env python
# coding=utf-8

from sys import exit
from random import randint

def death():
    quips  = ["You", "Nice", "Such", "I"]
    print quips[randint(0, len(quips) - 1)]
    exit(1)

def central_corridor():
    action = raw_input("> ");

    if action == "Shoot!":
        print "you are dead."
        return 'death'

    
        print "your head and eats you."
        return 'death'

    elif action == "tell a joke":
        print "putting him down"
        return 'laser_weapon_armory'

    else:
        print "Does not compute!"
        return 'central_corridor'

def laser_weapon_armory():
    print "get the bomb"
    code = "%d%d%d" %(randint(1, 9), randint(1, 9), randint(1, 9))
    guess = raw_input("[keypad]> ")
    guesses = 0

    while guess != code and guesses < 10:
        print "BZZZEDDD!"
        guesses += 1
        guess = raw_input("[keypad]> ")
    
    if guess == code:
        print "bridge"
        return 'the_bridge'
    else:
        print "ship"
        return'death'

def the_bridge():
    print "arm"

    action = raw_input("> ")

    if action == "throw the bomb":
        print "it goes off"
        return 'death'
   
    elif action == "slowly place the bomb":
        print "get off this tin can"
        return 'escape_pod'
    
    else:
        print "Does not compute"
        return "the_bridge"

def escape_pod():
    print "do you take?"

    good_pod = randint(1, 5)
    guess = raw_input("[pod #]> ")
    
    if int(guess) != good_pod:
        print "into jam jelly"
        return 'death'
    else:
        print "time. You won"
        exit(0)

ROOMS = {'death': death,'central_corridor': central_corridor, 'laser_weapon_armory':laser_weapon_armory, 'the_bridge': the_bridge, 'escape_pod': escape_pod}

def runner(map, start):
    next = start

    while True:
        room = map[next]
        print "\n---------"
        next = room()

runner(ROOMS, 'central_corridor')
