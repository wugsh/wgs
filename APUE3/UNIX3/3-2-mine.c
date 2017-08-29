#include "apue.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{	
	int fd, c;
	FILE  *fd1, *fd2;
	char ch;

        if ((fd = creat("kongdong", FILE_MODE)) < 0)
		printf("creat1 error is");	
	if (write(fd, buf1, 10) != 10)
		printf("writer error is ");
	if (lseek(fd, 16384, SEEK_SET) == -1)
		printf("error");
	if (write(fd, buf2, 10) != 10)
		printf("write2 error ");
        fd1 = fopen("kongdong", "r");
	fd2 = fopen("kongdong2","wr");

	while((ch = fgetc(fd1)) != EOF)
	{ 
		if(ch != '\0' && ch != ' ')
		fputc(ch, fd2);
	}

	fclose(fd1);
	fclose(fd2);
	exit(0);
}
