/*************************************************************************
	> File Name: point.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月24日 星期日 21时35分10秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

struct pt{
	int a;
};

int chgpt(struct pt **pt)
{
	*pt = malloc(sizeof(struct pt));
	(*pt)->a = 10;
}

int main()
{
	struct pt* pt;
	pt =  NULL;
	chgpt(&pt);

	printf("%d", pt->a);
}
