/*
 *求一个整型数字中有没有相同的部分，例如12386123这个整型数字中相同的部分是123，
 相同的部分至少应该是2位数，如果有相同部分返回Yes，如果没有则返回No。方法是先将
 整型数字转换到数组中，再判断。
 * */
#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, n, check = 0;
	char data[100];
	
	scanf("%s", data);
	n = strlen(data);
	for (i = 0; i < n - 3; i++){
		for (j = i+2; j < n; j++){
			if(data[i] == data[j]){
				if (data[i+1] == data[j+1]){
					check = 1;
					printf("Yes\n");
					break;
				}
			}
		}
		if (check == 1)
			break;
	}
	if (check == 0)
		printf("No\n");
	
//	printf("%d\n", n);	
//	puts(data);
	return 0;
}
