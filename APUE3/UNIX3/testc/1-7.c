#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINE 1024

int main(void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int	status;

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')	
			buf[strlen(buf) -1] = 0;
		if ((pid = fork()) < 0)
			printf("fork error\n");
		else if (pid == 0)
		{
			execlp(buf, buf, NULL);
			printf("couldn't execute: %s\n", buf);
			exit(127);
		}

		if (pid = waitpid(pid, &status, 0) < 0)
			printf("waitid error\n");
		printf("%% ");
	}
	exit(0);
}
