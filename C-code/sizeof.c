/*************************************************************************
	> File Name: sizeof.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时50分03秒
 ************************************************************************/

#include<stdio.h>

void func(char a[]){
    const char * str2 = "hello";
    char str3[] = "he";
    printf("%d, %d, %d, %d\n", sizeof(a), sizeof(str2), sizeof(str3), 
          sizeof("hello")); // 8, 8, 3, 6
}

int main()
{
    char str1[8];
    func(str1);
    return 0;
}
