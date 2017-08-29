from sys import exit 
from random import randint

class Game(object):
    def __init__(self, start):
        self.quips = ["you died", "your proud", "such", "I puppy"]
        self.start = start
    
    def play(self):
        next = self.start

        while True:
            print "\n-------"
            room = getattr(self, next)
            next = room()

    def death(self):
        print self.quips[randint(0, len(self.quips) - 1)]
        exit(1)

    def central_corridor(self):
        print "The Gothons"
        print "your crew"
        print "missing"
        print "put it"
        print "escape pod."
        print "\n"

        action = raw_input("> ")

        if action == "shoot!":
            print "you are dead"
            return 'death'
        
        elif action == "dodge!":
            print "your head and eats you"
            return 'death'

        elif action == "tell a joke":
            print "putting him down"
            return 'laser_weapon_armory'

        else:
            print "DOES NOT COMPUTE!"
            return 'central_corridor'

    def laser_weapon_armory(self):
        print "get the bomb"
        code = "%d%d%d" %(randint(1, 9), randint(1, 9), randint(1, 9))
        guess = raw_input("[keypad]> ")
        guesses = 0
    
        while guess != code and guesses < 10:
            print "BZZZZEDDD!"
            guesses += 1
            guess = raw_input("[keypad]>  ")

        if guess == code:
            print "bridge"
            return 'the bridge'

        else:
            print "ship"
            return 'death'
    
    def the_bridge(self):
        print "arm and don't want to set it off."

        action = raw_input("> ")
        
        if action == "throw the bomb":
            print "it goes off."
            return 'death'

        elif action == "slowly place the bomb":
            print "get off this tin can."
            return 'escape_pod'

        else:
            print "DOES NOT COMPUTE"
            return "the_bridge"

    def escape_pod(self):
        print "do you take?"

        good_pod = randint(1, 5)
        guess = raw_input("[pod #]> ")
        
        if int(guess) != good_pod:
            print "into jam jelly"
            return 'death'
       
        else: 
            print "time, You won!"
            exit(0)

a_game = Game("central_corridor")
a_game.play()

