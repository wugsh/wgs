#include "apue.h"

int 	globvar = 6;
char	buf[] = "a write to atdout\n";

int main(void)
{
	int	var;
	pid_t	pid, pid1;

	var = 88;
	if(write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
		err_sys("write error\n");
	printf("before fork\n");

	if((pid = fork()) < 0)
	{
		err_sys("fork error");

	}
	else if(pid == 0)
	{
		globvar++;
		var++;
	}
	else
	{
		sleep(2);
		
	}
	printf("pid = %ld, glob = %d, var = %d", (long)getpid(), globvar, var);
	printf("  parentpid = %ld\n", (long)getppid());
	exit(0);

}
