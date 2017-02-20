/*************************************************************************
	> File Name: temperature-moisture.c
	> Author: 
	> Mail: 
	> Created Time: 2017年02月20日 星期一 16时47分33秒
 ************************************************************************/

#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_TIME 85
#define DH11PIN 7

int dht11_val[5] = {0,0,0,0,0};
int errors = 0;

void dht11_read_val()
{
    uint8_t lststate = HIGH;
    uint8_t counter = 0;
    uint8_t j = 0, i;
    
    for (i = 0; i < 5; i++)
        dht11_val[i] = 0;
    pinMode(DH11PIN, OUTPUT);
    digitalWrite(DH11PIN, LOW);
    delay(18);
    digitalWrite(DH11PIN, HIGH);
    delayMicroseconds(40);
    pinMode(DH11PIN, INPUT);

    for (i = 0; i < 10; i++)
    {
        counter = 0;
        while(digitalRead(DH11PIN) == lststate) {
            counter++;
            delayMicroseconds(1);
            if (counter == 255)
                break;
        }
        lststate = digitalRead(DH11PIN);
        if (counter == 255)
            break;
        if ((i >= 4) && i%2 == 0) {
            dht11_val[j/8] <<=1;
            if (counter > 16)
                dht11_val[j/8] |= 1;
            j++;
        }
    }

    if ((j >= 40) && (dht11_val[4] == ((dht11_val[0] + dht11_val[1] + dht11_val[2] + dht11_val[3]) & 0xFF)))
    {
        printf("%d.%d\t%d.%d\n", dht11_val[0],dht11_val[1], dht11_val[2], dht11_val[3]);
        exit(1);
    }
    else {
        errors == errors + 1;
        if (errors > 5) {
            printf("0.0\t0.0");
            exit(2);
        }
    }
}

int main(void)
{
    if (wiringPiSetup() == -1)
        exit(1);

    while(1){
        dht11_read_val();
        delay(3000);   
    }
    return 0;
}


