/*************************************************************************
	> File Name: 168.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月26日 星期二 21时59分23秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	printf("input 5 numbers\n");
	int a[5];
	int *p;

	for (int i = 0; i < 5; i++)
		scanf("%d ",&a[i]);
	printf("\n");

	p = a;
	for (int i = 0; i < 5; i++)
		printf("a[%d] = %d ", i, *p++);
	
	return 0;
}
