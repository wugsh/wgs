/*************************************************************************
	> File Name: 172.2.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月30日 星期六 22时54分06秒
 ************************************************************************/

#include<stdio.h>

*FindMax(int *p, int n)
{
	int i, *max;
	max = p;
	for (i = 0; i < n; i++)
	{
		if (*(p + i) > *max)
			max = p + i;
	}
	return max;
}
int main()
{
	int *max;
	int a[5] = {1,2,3,4,5};

	max = FindMax(a, 5);
	printf("max = %d\n", *max);

	return 0;
}
