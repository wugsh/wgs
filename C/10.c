/*************************************************************************
    > File Name: 10.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年02月24日 星期三 22时09分20秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int a, b, c, d;
	scanf("%d %d %d", &a,&b,&c);
	if(a > b)
	{
		d = a;
		a = b;
		b = d;
	}
	if(a > c)
	{
	  d = a;
	  a = c;
	  c = d;
	}
	if(b > c)
	{
		d = b;
		b = c;
		c = d;
	}
	printf("%d,%d,%d\n",a,b,c);
	return 0;
}
