/*************************************************************************
	> File Name: 170.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月28日 星期四 22时31分59秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
	char *string[] = {"usa", "china", "jpan", "uk"};

	char **p;
	int i;
	p = string;

	for (i = 0; i < 4; i++)
	{
		printf("%s\n, %s\n", *(p++), *string[i]);
	}
	printf("\n");

	return 0;
}
