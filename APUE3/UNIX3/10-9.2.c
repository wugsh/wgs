#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "apue.h"

//unsigned int	sleep2(unsigned int);
static void	sig_int(int);

int main(void)
{
	unsigned int unslept;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		printf("signal (SIGINT) error\n");
	unslept = sleep(5);
	printf("sleep2 returned: %u\n", unslept);
	exit(0);
}

static void sig_int(int signo)
{
	int 		i, j;
	volatile int	k;
	
	printf("\nsig_int starting\n");
	for (i = 0; i < 300000; i++)
	{
		for (j = 0; j < 4000; j++)
			k += i * j;
	}
		printf("sig_int finished\n");
	
}


