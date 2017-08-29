#include <stdio.h>

int (*ptr)(const char * restrict);

int main()
{
	void *x = printf;
	ptr = x;
	(***ptr)("Hello\n");

	return 0;
}
