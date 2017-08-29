/*************************************************************************
	> File Name: feibonaqieshulie.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年05月28日 星期六 22时30分07秒
 ************************************************************************/

#include<stdio.h>

void main()
{
    int i;
    long f[31];
    f[1] = 1, f[2] = 1;

    for (i = 3; i < 31; i++)
        f[i] = f[i - 1] + f[i - 2];
    for (i = 1; i < 31; i++){
        printf("%10ld", f[i]);
        if (i % 5 == 0)
            printf("\n");
    }
}
