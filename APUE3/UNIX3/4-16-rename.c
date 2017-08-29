#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	if(fd = creat(argv[1], O_RDWR) != -1)
	{

		if(rename(argv[1], argv[2]) == -1)
			printf("error\n");
		else
			printf("success!\n");

	}
	else
		printf("creat file %s error\n",argv[1]);
	return 0;
}


