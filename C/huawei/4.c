/**
 *有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。

 输入描述:
 每组数据为一行一个整数n(小于等于1000)，为数组成员数,如果大于1000，则对a[999]进行计算。


 输出描述:
 一行输出最后一个被删掉的数的原始下标位置。
 *
 * */
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
