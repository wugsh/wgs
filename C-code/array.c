/*************************************************************************
	> File Name: array.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Wed 23 Aug 2017 03:13:23 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
	int data[5] = {1, 2, 3, 4, 5};
	int local, *p1, *p2;
//	p  = &data[2] - &data[1];
	p1 = &data[1];
	p2 = &data[2]; 
	printf ("p1 = %d, p2= %d\n", p1, p2);
	return 0;
}
