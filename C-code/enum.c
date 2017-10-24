/*************************************************************************
	> File Name: enum.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时29分46秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    enum digit {DNE, TWO, THREE};
    enum color {WHITE=0, RED=3, BLACK};
    printf("%d, %d\n", THREE, BLACK);

    return 0;
}

/*
 2, 4
 */
