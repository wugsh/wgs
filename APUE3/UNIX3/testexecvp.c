#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("main begin -----------\n");
	char *argv[] = {"ls","-l", NULL};

	if((execvp("ls",argv)) == -1)
		printf("execl error\n");
	printf("main over --------\n");

	return 0;
}
