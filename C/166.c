/*************************************************************************
	> File Name: 166.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月26日 星期二 20时15分08秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

exchange(int *x, int *y, int *z)
{
	if (*x > *y)
		swap(x, y);
	if (*x > *z)
		swap(x, z);
	if (*y > *z)
		swap(y, z);
}

int main()
{
	int a, b, c, *q1, *q2, *q3;
	printf("input three number: ");
	scanf("%d %d %d", &a, &b, &c);
	q1 = &a;
	q2 = &b;
	q3 = &c;
	exchange(q1, q2, q3);
	printf("\n %d, %d, %d\n", a, b, c);

	return 0;
}
