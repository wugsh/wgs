#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	char * const envp[] = {"AA=11","BB=22", NULL};
	printf("entering main----------\n");

	if((execle("./hello", "", NULL, envp)) == -1)
		perror("execl error");
	printf("main over-----\n");

	return 0;
}
