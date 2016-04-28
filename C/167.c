/*************************************************************************
	> File Name: 167.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年04月26日 星期二 21时47分55秒
 ************************************************************************/

#include<stdio.h>

struct student {
	int num;
	char name[20];
	char sex;
	int age;
	float score;
};

void main()
{
	struct student student1 = {1, "wugaosheng", 'M', 25, 100};
	struct student *p;
	p = &student1;
	printf("num = %d\n", p->num);
	printf("name = %s\n", p->name);
	printf("sex = %c\n", p->sex);
	printf("age = %d\n", p->age);
	printf("score = %0.1f\n", p->score);

}
