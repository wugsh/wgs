/*************************************************************************
	> File Name: 172.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月30日 星期六 22时08分49秒
 ************************************************************************/

#include <stdio.h>
//#include <conio.h>

int FindMax(int b[],int n)
{
	int i, *q;
	q = b;
	for (i = 0; i < n; i++)
	{
		if (*q < b[i])
			q = &b[i];
	}

	return *q;

}

int main()
{
	int max, *p, n;
	int a[5] = {1, 2, 3, 4, 5};
	
	n = sizeof(a) / sizeof(a[0]);
	p = a;
	max = FindMax(p,n);
	printf("max = %d\n", max);
	return 0;	
}
