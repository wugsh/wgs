#include <stdio.h>
#include <string>
#include <stdlib.h>

//第三种方法：定义全局变量，放在数据段上
char b[] = "linux"; 

int main()
{
	//第一种方法：定义局部变量，放在栈上
	char a[] = "linux";
	
	char *c = (char *)malloc (10);
	if (NULL == c)
	{
		printf("malloc error\n");
		return -1;
	}
	
}