#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define FILE_PATH "./3-11.c"

int main(void)
{
	int fd;
	if((fd = open(FILE_PATH, O_RDWR | O_CREAT | O_EXCL, 0666)) < 0){
		printf("open error\n");
		exit(-1);
	}else{
		printf("open sucess\n");
	}
 
	return 0;
}

