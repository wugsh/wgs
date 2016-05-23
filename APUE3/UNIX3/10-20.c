#include "apue.h"
#include <setjmp.h>
#include <time.h>

static void			sig_usr1(int);
static void			sig_alrm(int);
static sigjmp_buf		jumpbuf;
static volatile sig_atomic_t	canjump;
//static int 			canjump;

int main(void)
{
	if (signal(SIGUSR1, sig_usr1) == SIG_ERR)
		err_sys("SIGUSR1 error");
	if (signal(SIGALRM, sig_alrm)  == SIG_ERR)
		err_sys("SIGALRM error");

	pr_mask("starting main: ");
	
	if (sigsetjmp(jumpbuf, 1))
	{
		pr_mask("ending main: ");
		exit(0);
	}

	canjump = 1;
	for( ; ; )
		pause();
}

static void sig_usr1(int signal)
{
	time_t	starttime;

	if (canjump == 0)
		return;
	pr_mask("starting sig_usr1: ");
	
	alarm(3);
	starttime = time(NULL);
	printf("starttime is: %ld\n", starttime);
        for ( ; ; )	
	       if (time(NULL) > starttime + 5)
		       break;
       pr_mask("finishing sig_usr1: ");

       canjump = 0;
       siglongjmp(jumpbuf, 1);

}

static void sig_alrm(int signo)
{
	pr_mask("in sig_alrm: ");
}
