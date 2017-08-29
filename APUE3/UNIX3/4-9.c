#include "apue.h"
#include <stdio.h>
#include <fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int main(void)
{
    umask(0);
    printf("%o\n", umask);
    if (creat("foo", RWRWRW) < 0)
	err_sys("creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (creat("bar", RWRWRW) < 0)
	err_sys("creat error for bar");
	printf("%o\n", umask);
    	exit(0);
}
