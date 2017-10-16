/*************************************************************************
	> File Name: hashchazhao.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年05月24日 星期二 22时44分53秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#define Max 11
#define N 8

int hashtable[Max];

int func(int value)
{
	return value % Max;
}

int search(int key)
{
	int pos, t;
	pos = func(key);
	t = pos;
	while (hashtable[t] != key && hashtable[t] != -1)
	{
		t = (t + 1) % Max;
		if (pos == t)
			return -1;

	}
	if (hashtable[t] == -1)
		return;
	else
		return t;
}

void creathash(int key)
{
	int pos, t;
	pos = func(key);
	t = pos;
	while (hashtable[t] != -1)
	{
		t = (t + 1) % Max;
		if (pos == t){
			printf("The hashtable is full");
			return;
		}
	}
	hashtable[t] = key;
}

void main()
{
	int flag[50];
	int i, j, t;
	for (i = 0; i < Max; i++)
	    hashtable[i] = -1;
    for (i = 0; i < 50; i++)
        flag[i] = 0;

	srand((unsigned long)time(0));
	i = 0;
	while (i != N){
		t = rand() % 50;
		if (flag[t] == 0){
			creathash(t);
			printf("%2d", t);
			for (j = 0; j < Max; j++)
				printf("(%2d)", hashtable[j]);
			printf("\n");
			flag[t] = 1;
			i++;
		}
	}
	printf("please input the number which you want search: ");
	scanf("%d", &t);
	if (t > 0 && t < 50){
		i = search(t);
		if (i != -1)
			printf("search successed and the location is : %d\n", i);
		else
			printf("search error!\n");
	}
	else
		printf("input error!\n");
	
}
