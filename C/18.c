/*************************************************************************
    > File Name: 18.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年03月01日 星期二 22时08分51秒
 ************************************************************************/

#include<stdio.h>

int paixu(int a, int b, int c)
{
	int d;

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
}

int main()
{
	int a, b, c, s;

	printf("输入三条边的长度：\n");
	scanf("%d %d %d",&a,&b,&c);
	
	int paixu(int a, int b, int c);
	
	if (a + b > c && c - a < b)
	{
		if (a == c && b == c)
		{
			printf("构成等边三角形\n");
		}
		if (a != b == c || a == b != c)
		{
			printf("构成等边三角形\n");
		}
		if ( a * a + b * b == c * c)
		{
			printf("构成直角三角形\n");
		}
	
	} else {
			printf("这三个数无法构成三角形\n");
	}

	printf("a = %d, b = %d, c = %d\n",a, b, c);

	return 0;
}
