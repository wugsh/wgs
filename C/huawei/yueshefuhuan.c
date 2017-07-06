#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 9
#define ERROR 0
#define OK 1
int keyW[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

typedef struct LNode{
	int data;
	struct LNode  *next;	
} LNode;
typedef struct LNode *LinkList;

void  Joseph(LinkList p, int m, int x)
{
	LinkList q;
	int i;
	if (x == 0)
		return;
	q = p;
	m %= x;
	if (m == 0)
		m = x;
	for (i = 1; i <= m; i++){
		p = q;
		q = p->next;
	}
	p->next = q->next;
	i = q->data;
	printf("%d ", q->data);
	free(q);
	Joseph(p, i, x - 1);
	
}

int main()
{
	int i, m;
	LinkList Lhead, p, q;
	Lhead = (LinkList)malloc(sizeof(LNode));
	if (!Lhead)
		return ERROR;
	Lhead->data = keyW[0];
	Lhead->next = NULL;
	p = Lhead;
	
	for (i = 1; i < 9; i++){
		if (!(q = (LinkList)malloc(sizeof(LNode))))
			return ERROR;
		q->data = keyW[i];
		p->next = q;
		p = q;
	}
	p->next = Lhead;
	printf("please input a number m: \n");
	scanf("%d", &m);
	printf("output the queue:\n");
	Joseph(p, m, N);
	printf("\n");
	return 0;
}
