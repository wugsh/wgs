/*************************************************************************
    > File Name: 11-2.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年02月26日 星期五 16时01分46秒
 ************************************************************************/

#include <stdio.h>
#include "apue.h"
#include <pthread.h>

pthread_t ntid;

void printids(const char *s)
{
	pid_t	    pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);

}

void *thr_fn(void *arg)
{
	printids("new thread: ");
	return((void *)0);
}

int main(void)
{
	int	err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if (err != 0)
		err_exit(err, "can't create thread");
	printids("main thread：");
	sleep(2);
	exit(0);
}
