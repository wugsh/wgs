/*************************************************************************
	> File Name: 173.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年05月01日 星期日 22时32分56秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
connection(char *s, char *t, char *q)
{
	int i = 0;
	for (; *s != '\0';)
	{
		*q = *s;
		s++;
		q++;
	}

	for (;*t != '\0';)
	{
		*q = *t;
		t++;
		q++;
	}
	*q = '\0';
}

int main(void)
{
	char fa[60], *p;
	char str[] = {"one world"};
	char t[] = {"one dream"};
	p = fa;
	connect(str, t, p);
	printf("%s\n", p);
	return 0;
}
