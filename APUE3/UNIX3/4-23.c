#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	if(chdir(argv[1]) < 0)
		printf("error\n");
	else 
		printf("succeeded\n");
	return 0;
}
