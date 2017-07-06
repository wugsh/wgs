#include<stdio.h>

typedef struct link{
	struct link *next;
	int data;
}node;

int main()
{
	int i, N;
	node a[1000], *p;
	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N-1; i++){
			a[i].data = i;
			a[i].next = &a[i+1];	
		}
		a[i].data = i;
		a[i].next = a;

//		for (i = 0; i <= N; i++){
//			printf("%d ", a[i].data);
//		}
		p = a;
		while(1){
			if (p == p->next){
				printf("%d\n",p->data);
				break;
			}
			p->next->next = p->next->next->next;
			p = p->next->next;
		}
	}
	return 0;	
}
