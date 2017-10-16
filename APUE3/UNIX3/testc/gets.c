#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define SIZE 1024

int main(void)
{
	//int fd1, fd2;
	char buf1[SIZE], buf2[SIZE];

	
	
	
	while(1)
	{
		printf("input your name:\n");
		if(strcmp(gets(buf1), "dslab") == 0)
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
	return 0;
}
