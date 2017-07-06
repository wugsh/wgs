/**
 *写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）

 输入描述:
 输入一个十六进制的数值字符串。


 输出描述:
 输出该数值的十进制字符串。
 *
 * */

#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, l, m; 
	int count = 0;
	char str[100];
	while(gets(str)){
	l = strlen(str);
	count = 0
	//printf("l = %d\n", l);
 	for(i = l-1; i > 1; i--){
        m = 1;
		j = l - 1 - i;
		while (j > 0){
			m *= 16;
			j--;
		}
		if ('0' <= str[i] && str[i] <= '9')
			count += (str[i] - '0') * m;
		if ('A' <= str[i] && str[i] <= 'F')
			count += ((str[i] - 'A') + 10) * m;
    }
	printf("%d\n", count);
   }
	return 0;
}
