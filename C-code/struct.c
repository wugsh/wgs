/*************************************************************************
	> File Name: struct.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 22 Aug 2017 04:37:21 PM CST
 ************************************************************************/

#include<stdio.h>

struct pp
{
	int a;
	int b;
};

struct res
{
	struct pp A;
	struct pp B;
};

int main()
{
	struct pp num[5] = {1,2,3,4,5,6,7,8,9,0};
	int i;

	struct pp one;
	one.a = 1;
	one.b = 2;
	struct res two;
	two.A.a = 11;
	two.B.b = 22;
	
	struct pp *three;
	three = &one;
	three->a = 33;
	three->b = 44;
	printf ("two.A.a = %d, two.B.b = %d\n", two.A.a, two.B.b);
	printf ("t->a = %d,t->b = %d\n", three->a, three->b);
	printf ("one.a = %d, one.b = %d\n", one.a, one.b);
	for (i = 0; i < 5; i++){		
		printf ("num[%d].a = %d, num[%d].b = %d\n",i, num[i].a, i, num[i].b);
	}
	return 0;
}
