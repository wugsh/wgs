/*************************************************************************
	> File Name: struct-func.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时36分48秒
 ************************************************************************/

#include<stdio.h>

/*void func(void){
    int a;
    printf("%d\n", a);
}*/

int main()
{
    struct {
        int a, b;
    }t = {1};
    printf("%d\n", t.a / t.b); //
    
    int e;
    printf("%d\n", e); //

  //  static int c;
  //  printf("%d\n", c); //

    int d;
    /*void func(void){
        printf("%d\n", d);
    }*/
    
    return 0;
}
