/*
 *求两个字符串的乘积，结果存到字符串中，例如字符串一中存的“657891” 字符串二中存的“521,
 *分别将字符串中的字符转换成整型数字，进行计算后，再转换成字符类型存储起来。
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[100], b[100];
	int A = 0, B = 0, i = 0, l, n;
	scanf("%s", a);
	scanf("%s", b);
	A = atoi(a) * atoi(b);
	printf("%d\n", A);
	while(1){
		a[i] = A % 10;
		A = A / 10;
		if (A == 0){
			break;
		}
		i++;
	}
	for (l = i; l >= 0; l--){
		b[i-l] = a[l];
		printf("%c",a[l]);
	}
	printf("\n");
	return 0;
}
