#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("entering main -------\n");

	if(execl("./hello","1","2", "3", NULL) == -1)
		perror("execl error");
	printf("main over ----------\n");

	return 0;
	
}

