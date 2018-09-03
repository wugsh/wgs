/*************************************************************************
	> File Name: struct-func.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时36分48秒
 ************************************************************************/

#include<stdio.h>

int e;

void func(void){
    printf("%d\n", e); // 0
}

int main()
{
/*    struct {
        int a, b;
    }t = {1};
    printf("%d\n", t.a / t.b); //
 */   
    int b;
    printf("%d\n", b); // 0

    static int c;
    printf("%d\n", c); // 0

    func();
     
    return 0;
 }
