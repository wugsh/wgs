/*************************************************************************
	> File Name: movezones.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年09月14日 星期三 20时43分09秒
 ************************************************************************/

#include<stdio.h>


void main()
{
    int i, j, n = 0;
    int a[5] = {0,1,23,0,9};

    for(i = 0; i < 5; i++){
        if (a[i] == 0){
            n++;

            for(j = i; j < 5; j++){
                a[j] = a[j+1];
            }
        }
    }
    for(i = 4; i >= 5 - n; i--)
        a[i] = 0;

    for(i = 0; i < 5; i++){
       printf(" %d ", a[i]);
   }
    printf("\n");
}
