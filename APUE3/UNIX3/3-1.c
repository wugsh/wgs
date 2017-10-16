#include<sys/types.h>
#include<unistd.h>
#include "apue.h"
#include<stdio.h>

int main(void)
{
	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek 0k\n");
	exit(0);
}
