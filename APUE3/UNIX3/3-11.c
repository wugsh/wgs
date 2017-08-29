#include "apue.h"
#include<fcntl.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int val;
    if (argc != 2)
	err_quit("usage: a.out <descriptor#>");

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
	err_sys("fcntl error for fd %d", atoi(argv[1]));
    switch (val & O_ACCMODE) {
    case O_RDONLY:
	printf("%o\n",O_ACCMODE);
	printf("%o\n",O_RDONLY);

	printf("%s\n",argv[1]);
	printf("read only");
	break;
    case O_WRONLY:
	printf("%s\n",argv[1]);

	printf("write only");
	break;
    case O_RDWR:
	printf("%s\n",argv[1]);

	printf("read write");
	break;
    default:
	err_dump("unknown access mode");
    }
    if (val & O_APPEND)
	printf(", append\n");
    	printf("%o\n",O_APPEND);

    if (val & O_NONBLOCK)
	printf(", nonblocking");
    	printf("%o\n", O_NONBLOCK);
    if (val & O_SYNC)

	printf(", synchronous writes");
    	printf("%o\n",O_SYNC);
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
	printf(", synchronous writes");
    	printf("%o\n",O_FSYNC);
#endif
    printf("%o\n",O_FSYNC);

    putchar('\n');
    exit(0);
}

