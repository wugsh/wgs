#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define Status int
#define OK 1
#define ERROR 0

typedef struct List {
    ElemType data;
    struct List *next;
} linklist;

Status CreateList(linklist * L)
{
    //创建一个单链表
    linklist *p;
    L->next = NULL;
    p = (linklist *) malloc(sizeof(linklist));
    if (!p)
	return ERROR;
    scanf("%d", &p->data);
    while (p->data != 0) {
	p->next = L->next;
	L->next = p;
	p = (linklist *) malloc(sizeof(linklist));
	scanf("%d", &p->data);
    }

    return OK;
}

Status reverse(linklist * L)
{
    //单链表逆置
    linklist *p, *q;
    p = L->next;
    L->next = NULL;
    while (p) {
	q = p;
	p = p->next;
	q->next = L->next;
	L->next = q;
    }
    return OK;
}

Status listinsert(linklist * L, int i, ElemType e)
{
    //单链表的简单插入
    int j;
    linklist *p, *q;
    q = L;
    p = (linklist *) malloc(sizeof(linklist));
    if (!p)
	return ERROR;
    p->data = e;
    for (j = 0; j < i - 1; ++j) {
	q = q->next;
    }
    p->next = q->next;
    q->next = p;
    return OK;
}

Status listdel(linklist * L, int i, ElemType * e)
{
    //单链表的删除操作
    int j;
    linklist *p;
    linklist *q = (linklist *) malloc(sizeof(linklist));
    p = L;
    for (j = 0; j < i - 1; ++j) {
	p = p->next;
    }
    q = p->next;
    *e = q->data;
    p->next = q->next;
    q->next = NULL;
    free(q);

    return OK;
}

linklist *MergeList(linklist * La, linklist * Lb)
{
    //合并单链表
    linklist *Lc;
    linklist *pa, *pb, *pc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;
    while (pa && pb) {
	if (pa->data <= pb->data) {
	    pc->next = pa;
	    pc = pa;
	    pa = pa->next;
	} else {
	    pc->next = pb;
	    pc = pb;
	    pb = pb->next;
	}
    }
    pc->next = pa ? pa : pb;
    return Lc;			//返回合并后链表的头指针
}

Status display(linklist * L)
{
    linklist *p;
    p = L->next;
    while (p) {
	printf("%d ", p->data);
	p = p->next;
    }
    printf("\n");
    return OK;
}

int main(void)
{
    int i, di;
    ElemType e, de;

    linklist *L = (linklist *) malloc(sizeof(linklist));	//要想将修改的值带回，需用动态内存分配
    //原因是静态分配的内容在被调函数体结束后就会由系统自动将内存回收，而动态内存分配的变量在函数结束后
    //不会立即释放，需要程序员手动添加代码，手动释放堆区中的内存
    linklist *La = (linklist *) malloc(sizeof(linklist));
    linklist *Lb = (linklist *) malloc(sizeof(linklist));
    linklist *Lc;

    if (!L)
	return ERROR;
    printf("Please create a linklist:\n");
    CreateList(L);
    printf("the list after create is ;\n");
    display(L);
    reverse(L);			//反转链表
    printf("The list after reverse is :\n");
    display(L);
    printf("please input the insert lo & elem:\n");
    scanf("%d%d", &i, &e);
    listinsert(L, i, e);
    printf("The list after insert is ;\n");
    display(L);
    printf("please input the del number :\n");
    scanf("%d", &di);
    listdel(L, di, &de);
    printf("The del num is %d\n", de);
    printf("The list after del is :\n");
    display(L);
    printf("create the list la:\n");
    CreateList(La);
    reverse(La);
    printf("create the list lb:\n");
    CreateList(Lb);
    reverse(Lb);
    printf("the list after merge is :\n");
    Lc = MergeList(La, Lb);
    display(Lc);
    free(L);
    free(La);
    free(Lb);			//手动释放堆中分配的内存
    return 0;
}
