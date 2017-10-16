#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("entering main process ----\n");
	execlp("ls","ls", "-l", (char *)0);
	printf("exiting main process-----\n");

	return 0;
}
