/*************************************************************************
	> File Name: data2.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月07日 星期五 21时49分50秒
 ************************************************************************/

#include<stdio.h>
#include<limits.h> 

int main() 
{ 
     printf("UCHAR_MAX=%-10d SCHAR_MIN=%-10d SCHAR_MAX=%-10d\n",UCHAR_MAX,SCHAR_MIN,SCHAR_MAX); 
     printf("SHRT_MIN=%-11d SHRT_MAX=%-11d USHRT_MAX=%-11d\n",SHRT_MIN,SHRT_MAX,USHRT_MAX); 
    printf("INT_MIN=%-12d INT_MAX=%-12d UINT_MAX=%-12u\n",INT_MIN,INT_MAX,UINT_MAX); 
    printf("LONG_MIN=%-11ld LONG_MAX=%-11ld ULONG_MAX=%-11u\n",LONG_MIN,LONG_MAX,ULONG_MAX); 
    return 0; 
}
