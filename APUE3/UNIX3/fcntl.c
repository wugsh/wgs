#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv[])
{
	printf("entering main -------\n");

	if(fcntl(2, F_SETFD, FD_CLOEXEC) == -1)
		perror("fcntl error");
	else if(execlp("ls","ls","-l",NULL) == -1)
		perror("execlp error");
	printf("mai over ----------\n");

	return 0;

}
