#include "apue.h"
#include <errno.h>

static void sig_hup(int signo)
{
	printf("SIGHUP received, pid = %ld\n", (long)getpid());

}
static void pr_ids(char *name)
{
	printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n", name, (long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
}

int main(void)
{
	char	c;
	pid_t	pid;

	pr_ids("parent");
	if ((pid = fork()) < 0)
	{
		printf("fork error\n");
	} else if (pid > 0) {
		sleep(10);
		printf("pid = %ld, ppid = %ld\n", (long)getpid(), (long)getppid());
	} else {
		pr_ids("child ");
		signal(SIGHUP, sig_hup);
		kill(getpid(), SIGHUP);
		pr_ids("child");
		if (read(STDIN_FILENO, &c, 1) != 1)
			printf("read error %d on controlling TTY\n",errno);


	}
	exit(0);
}
