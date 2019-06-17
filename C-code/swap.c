#include <stdio.h>

int main()
{
	int a = 3;
	int b = 5;
	printf("数值交换前\n");
	printf("a = %d, b = %d\n", &a, &b);

	a = a^b;
	b = a^b;
	a = a^b;

	printf("数值交换后\n");
	printf("a = %d, b = %d\n", &a, &b);

	return 0;
}
