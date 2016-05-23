#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	pid_t	pid;
	
	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
	{
		if (execl("/home/wgs/UNIX3/lls", "foo", "hello", (char *)0) < 0)
			printf("excel error\n");
	}
	if(waitpid(pid, NULL, 0) < 0)
		printf("waitpid error\n");
	exit(0);
}
