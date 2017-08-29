/*************************************************************************
	> File Name: big.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 22 Aug 2017 07:59:02 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
	int i, n, mast;
	int data[101];
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i++)
			scanf("%d", data+i);
	}
	mast = data[0] * data[0];
	printf("%d\n", mast);
	return 0;
}
