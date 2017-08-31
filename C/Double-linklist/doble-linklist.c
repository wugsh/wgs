#include <stdio.h>
#include <stdlib.h>

typedef struct doublelinklist{
	int data;
	struct doublelinklist *next;
	struct doublelinklist *prior;

}Doublelink;

Doublelink *creatlink(Doublelink *L)
{	
	int num;
	Doublelink *p, *q;
	L->next = NULL;
    q = (Doublelink *)malloc(sizeof(Doublelink));
    if (!q)
        return NULL;
    q = L;
	while(1){
		p = (Doublelink *)malloc(sizeof(Doublelink
                                 ));
        scanf("%d", &num);
        if(num == 0)
            break;
        p->data = num;
		p->prior = q;
		q->next = p;
        q = p;
    }
    q->next = NULL;
	printf("createlink over\n");
	return L;
}

void displaylink(Doublelink *L)
{
	Doublelink *p;
	p = L->next;
	while(p){
		printf("%d ", p->data);
		free(p);
		p = p->next;

	}
	L->next = NULL;
    printf("\n");
}

int main()
{
	Doublelink *L;
	L = (Doublelink *)malloc(sizeof(Doublelink));
    printf("Input num for the linklist, 0 is the last one:\n");
	creatlink(L);
	displaylink(L);
	return 0;
}
