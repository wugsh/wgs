/*************************************************************************
	> File Name: test.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年03月18日 星期五 10时13分51秒
 ************************************************************************/

#include<stdio.h>

namespace myname
{
	int var = 42;
}
extern "C" double _ZN6myname3varE;

int main()
{
	printf("%d\n",_ZN6myname3varE);
	return 0;
}
