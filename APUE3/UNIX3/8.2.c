#include "apue.h"

static void  f1(void), f2(void);

int main(void)
{
	f1();

	f2();

	_exit(0);
}

static void f1(void)
{
	pid_t	pid;
	
	if ((pid = vfork()) == -1)
		printf("vfork error\n");
}

static void f2(void)
{
	char	buf[1000];
	int	i;

	if (i =0, i < sizeof(buf), i++ )
	{
		buf[i] = 0;
	}
}
