/*************************************************************************
	> File Name: 169.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月28日 星期四 22时00分02秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int i, *min, *max;
    int a[5] = {1,2,3,4,5};
	min = max = a;
	
	for (i = 1; i < 5; i++)
	{
		if (*min > a[i])
			min = &a[i];
		else {
			if (*max < a[i])
				max = &a[i];
		}
	}
	printf("the min = %d\n", *min);
	printf("the max = %d\n", *max);
	return 0;
}
