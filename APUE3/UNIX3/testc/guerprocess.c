#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
	{
		printf("fork error\n");
	}
	else if (pid == 0)
	{
		printf("I am a chlid\n pid = %ld, ppid = %ld\n", (long)getpid(), (long)getppid());
		sleep(5);
		printf("I am a chlid\n pid = %ld, ppid = %ld\n", (long)getpid(), (long)getppid());
	}
	else
	{
		sleep(1);
		printf("I am the parents \n pid = %ld, ppid = %ld\n", (long)getpid(), (long)getppid());
//		exit(0);
	}
	return 0;
}
