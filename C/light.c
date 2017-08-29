/*************************************************************************
	> File Name: light.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年03月28日 星期一 21时12分42秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int a[10]={-1};
	
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			int k = i;
			while(k <= 10){
								a[k] = -a[k];
								k = k * j;
											
			}

		}
   		printf("第%d个孩子拉灯\n",i);
	}

	for(int l = 1; l <= 10; l++)
	{
		if (a[l] == 1)
			printf("%d ", l);
	}

	printf("\n");

	return 0;
}
