#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	int	status;
	printf("pid = %ld\n", (long)getpid());

	if (status = system("date") < 0)
	{
		printf("system() error\n");
	}else{
		pr_exit(status);
		printf("pid = %ld\n", (long)getpid());
	     }
	if ((status = system("nosuchcommand")) < 0)
		printf("system() error\n");
	else{
                pr_exit(status);
                printf("pid = %ld\n", (long)getpid());
            }

	if ((status = system("who, exit, 44")) < 0)
		printf("system() error\n");
	else{
                pr_exit(status);
                printf("pid = %ld\n", (long)getpid());
            }

	exit(0);
}
