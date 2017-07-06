#include <stdio.h>
  
typedef struct queue{
    struct queue *next;
    int val;
}QUEUE_S;
  
int main(void){
    int n, i;
    QUEUE_S q[1000], *p;
  
    while (scanf("%d", &n) != EOF){
  
        /* 初始化循环队列 */
        for (i = 0; i < n - 1; i++){
            q[i].val = i;
            q[i].next = &q[i + 1];
        }
        q[i].val = i;
        q[i].next = q;
  
        p = q;
        while (1){
            if (p == p->next){
                printf("%d\n", p->val);
                break;
            }
            p->next->next = p->next->next->next; /* 删除间隔两个之后的元素 */
            p = p->next->next; /* 更新指针位置 */
        }
    }
    return 0;
}
