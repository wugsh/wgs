#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
	int fd ;
	int n;
	char buf[1024] = "hello word";

	fd = open("/dev/dev_fifo0",O_RDWR);
	if(fd < 0){
		perror("Fail ot open");
		return -1;
	}

	printf("open successful ,fd = %d\n",fd);
	
	n = write(fd,buf,strlen(buf));
	if(n < 0){
		perror("Fail to write");
		return -1;
	}

	printf("write %d bytes!\n",n);

	n = write(fd,buf,strlen(buf));
	if(n < 0){
		perror("Fail to write");
		return -1;
	}

	printf("write %d bytes!\n",n);
	return 0;
}
