/*************************************************************************
    > File Name: 19.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年03月02日 星期三 21时46分23秒
 ************************************************************************/

#include<stdio.h>

void insort(int s[], int n)
{
	int i, j;
	for (i = 2; i < n; i++)
	{
		s[0] = s[i];
		j = i - 1;
		while(s[0] < s[j])
		{
			s[j+1] = s[j];
			j--;
		}
		s[j+1] = s[0];
	}
}

void main()
{
	int	i, a[11];
	printf("请输入10个数据：\n");
	for (i = 1; i <= 10; i++)
		scanf("%d",&a[i]);
	insort(a, 10);
	printf("排序后的顺序是：\n");
	for (i = 1; i <= 10; i++)
		printf("%5d",a[i]);
	printf("\n");

}
