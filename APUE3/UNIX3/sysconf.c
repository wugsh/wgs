#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<limits.h>

int main()
{
	static long a;
	a = sysconf(_SC_VERSION);
	printf("%ld\n",a);
	return 0;
}
