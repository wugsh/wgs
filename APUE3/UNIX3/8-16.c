#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *env_init[] = {"PATH =UNIX3", NULL};

int main(void)
{
	pid_t	pid;

	if((pid = fork()) < 0)
	{
		printf("fork error\n");
	}
	else if(pid == 0)
	{
		if(execle("./hello", "echoall","myarg1",
					"MY ARG2", (char *)0, env_init) < 0)
			printf("excel error1\n");

	}
	/*
	if(waitpid(pid, NULL,0) < 0)
		printf("wait error\n");
	if((pid = fork()) < 0)
		printf("fork error\n");
	else if(pid == 0)
	{
		if(execlp("./hello","echoall", "only 1 arg", (char *)0) < 0)
			printf("excelp error2\n");
	}
	*/
	exit(0);
}
