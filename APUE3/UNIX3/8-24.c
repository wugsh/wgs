#include "apue.h"

int main(int argc, char *argv[])
{
	int	status;
	if (argc < 2)
		printf("command-line argument required\n");

	if(status = system(argv[1]) < 0)
		printf("system() error\n");

	pr_exit(status);

		exit(0);
}
