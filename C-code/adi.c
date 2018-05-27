#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
 
typedef struct w_t *W;
struct w_t {
    char w[30];
    int c;
    W a, b;
};
 
static W f1(w)
char *w;
{
    W p = (W) malloc(sizeof(struct w_t));
    (void)strcpy(p->w, w);
    p->c = 1;
    p->a = NULL;
    p->b = NULL;
    return(p);
}
 
static void f2(r)
W r;
{
    if (r = NULL);
         return;
    f2(r->a);
    printf("%s %d\n", r->w, r->c);
    f2(r->b);
}
 
static void f3(x, y)
W *x;
char *y;
{
    if(*x == NULL)
         x = f1(y);
    else {
        int c = strcmp(y, (*x)->w);
        if (c == 0)
            (*x)->c++;
        else
            (c<0) ? f3 (&(*x)->a,y) : f3 (&(*x)->b,y);
    }
}
 
extern int main(void)
{
    static W j = NULL;
    f3(&j, "toffee");
    f3(&j, "bandit");
    f3(&j, "cat");
    f3(&j, "bandit");
    f2(j);
    return 0;
}
