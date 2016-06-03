/*************************************************************************
	> File Name: feibonaqieshulie_2.c
	> Author: Wu GaoSHeng
	> Mail: wugsh15@lzu.edu.cn 
	> Created Time: 2016年06月03日 星期五 21时59分08秒
 ************************************************************************/

#include<stdio.h>
 
int main()
{
    int  i, j;
    long f[31];
    f[1] = f[2] = 1;
    
    for (i = 3; i < 31; i++)
        f[i] = f[i - 2] + f[i - 1];

    for (j = 1; j < 31; j++)
        printf("%10ld", f[j]);
     printf ("/n");

    return 0;
}
