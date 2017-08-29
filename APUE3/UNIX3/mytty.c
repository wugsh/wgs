#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE 1024

int main(void)
{
	int fd1, fd2;
	char buf1[SIZE], buf2[SIZE];
	int login(char *);

	while(1)
	{
		if((fd1=open("/dev/tty113", O_EXCL|O_CREAT)) == -1) 
//	parse the parameters from init, get which tty to open
		{
			perror(strerror(errno));
			continue;
		}
		else
		{
			printf("open fd1 success\n");
			break;
		}
	}
	dup2(0, fd1);
	close(0);
	dup2(1, fd1);
	close(1);
	dup2(2, fd1);
	close(2);
	//set attr

	//login();

//	close STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO


	if((fd2=openat(fd1, "/dev/tty", O_EXCL)) == -1)
//	open the tty, which get from the first step

	{
		printf("openat tty error\n");
		return 2;
	}
	if(dup2(fd2, 0)==-1|dup2(fd2, 1)==-1|dup2(fd2, 2)==-1)
//	 reopen STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO
	{
		printf("open STDIN_FILENO or STDOUT_FILENO or STDERR_FILENO error\n");
		return 3;
	}


	/*
	  modify the tty's attribute

	 */
	gets(buf1);

       int login(buf1)
	{
	while(1)
	{
		printf("input your name:\n");
		if(strcmp(buf1, "dslab") == 0)
		{
			printf("input your passwd:\n");
			if(strcmp(gets(buf2), "123") == 0)
			{
				printf("welcome!\n");
				break;
			}
			else
			{
				printf("your passwd error\n");
				continue;
			}
		}
		else
		{	
			printf("your name error\n");
			continue;
		}
	}
	}
//	system("gnome-terminal -e ./mytty.c");
	return 0;
	close(fd1);
}
