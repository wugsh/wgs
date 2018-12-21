import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
trig=1 #send-pin
echo=3 #receive-pin
GPIO.setup(trig,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(echo,GPIO.IN)
 
def Measure():
 
    #send
    GPIO.output(trig,True)
    time.sleep(0.00001) #1us
    GPIO.output(trig,False)
 
    #start recording
    while GPIO.input(echo)==0:
        pass
    start=time.time()
 
    #end recording
    while GPIO.input(echo)==1:
        pass
    end=time.time()
 
    #compute distance
    distance=round((end-start)*343/2*100,2)
    print("distance:{0}cm,{1}m".format(distance,distance/100))
    
while True:
    Measure()
    time.sleep(1)
    
GPIO.cleanup();
 

