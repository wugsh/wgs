/*************************************************************************
	> File Name: signed-unsigned.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时18分13秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    signed char c1 = -1; 
    int i1 = (int)c1;

    unsigned char c2 = -1;
    int i2 = (int)c2;

    int i3 = (int)(3 * 1.0 / 2 * 3);
    printf("%d, %d, %d\n", i1, i2, i3);

    return 0;
}

/*
 -1, 255, 4
 */
