#include "apue.h"
#ifdef	SOLARIS
#define	PSCMD	"ps -a -o pid,ppid,s,tty,com"
#else
#define PSCMD	"ps -o pid,ppid,state,tty,command"
#endif

int main(void)
{
	pid_t	pid;
	printf("pid = %ld, ppid = %ld\n", (long)getpid(), (long)getppid());
	if((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
	{	sleep(1);
		printf("pid = %ld, ppid = %ld\n", (long)getpid(), (long)getppid());
	}
	else
	{
		system(PSCMD);
		printf("pid = %ld, ppid = %ld\n", (long)getpid(), (long)getppid());
	}
	exit(0);
}
