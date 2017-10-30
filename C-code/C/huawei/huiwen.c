/*
 *比较一个数组的元素 是否为回文数组
 * */
#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j = 0, mid;
	char str[100];

	scanf("%s", str);
	n = strlen(str);
	mid = n / 2;
	for (i = n-1; i >= mid; i--){
		if (str[j++] != str[i]){
			printf("No\n");
			break;
		}
	//	printf("Yes\n");
	}
	if (j == i+1)
		printf("Yes\n");
	return 0;
}
