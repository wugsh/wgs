/*************************************************************************
	> File Name: LinkList1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年06月23日 星期五 11时23分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define ELemType int
#define Status int
#define OK 1
#define ERROR 0

typedef struct List
{
    ELemType data;
    struct List *next;
}linklist;

//创建链表，尾插法
Status CreatList(linklist *L)
{
    linklist *p, *r;
    r = L;
    p = (linklist *)malloc(sizeof(linklist));
    if(!p)
        return ERROR;
    scanf("%d", &p->data);
    while (p->data != 0){
        r->next = p;
        r = p;
        p = (linklist *)malloc(sizeof(linklist));
        scanf("%d", &p->data);
    }
    r->next = NULL;
    return OK;
}

//打印链表
Status display(linklist *L)
{
    linklist *p;
    p = L->next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

//单链表逆置
Status reverse(linklist *L)
{
    linklist *p, *q;
    p = L->next;
    L->next = NULL;
    while (p){
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
    return OK;
}

//单链表插入
Status listinsert(linklist *L, int i, ELemType e)
{
    int j;
    linklist *p, *q;
    q = L;
    p = (linklist *)malloc(sizeof(linklist));
    if (!p)
        return ERROR;
    p->data = e;
    for(j = 0; j < i - 1; j++){
        q = q->next;  
    }
    p->next = q->next;
    q->next = p;
    return OK;
    
}

//单链表删除操作
Status listdel(linklist *L, int i, ELemType *e)
{
    int j;
    linklist *p;
    linklist *q = (linklist *)malloc(sizeof(linklist));
    p = L;
    for (j = 0; j < i-1; j++){
        p=p->next;
    }
    q = p->next;
    *e = q->data;
    p->next = q->next;
    q->next =NULL;
    free(q);
    return OK;
}

int main()
{
    int i, di;
    ELemType e, de;

    linklist *L = (linklist *)malloc(sizeof(linklist));
    if (!L)
        return ERROR;
    printf("creat a linklist\n");
    CreatList(L);
    printf("L = %d \n", L->next->data);
    display(L);
    //linklist *m;
   // m = L;
    //display(L);
    reverse(L);
    display(L);
    printf("please input the insert lo & elem:\n");
    scanf("%d %d", &i, &e);
    listinsert(L, i, e);
    printf("please input the del number:\n");
    scanf("%d", &di);
    listdel(L, di, &de);
    display(L);
    free(L);
    return 0;

}

