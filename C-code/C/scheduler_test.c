#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define DEATH(mess) { perror(mess); exit(errno); }

void printpolicy (int policy)
{

    /* SCHED_NORMAL = SCHED_OTHER in user-space */

    if (policy == SCHED_OTHER)
        printf ("policy = SCHED_OTHER = %d\n", policy);
    if (policy == SCHED_FIFO)
        printf ("policy = SCHED_FIFO = %d\n", policy);
    if (policy == SCHED_RR)
        printf ("policy = SCHED_RR = %d\n", policy);
}

int main (int argc, char **argv)
{
    int policy;
    struct sched_param p;

    /* obtain current scheduling policy for this process */
    //获取进程调度的策略
    policy = sched_getscheduler (0);
    printpolicy (policy);

    /* reset scheduling policy */

    printf ("\nTrying sched_setscheduler...\n");
    policy = SCHED_FIFO;
    printpolicy (policy);
    p.sched_priority = 50;
    //设置优先级为50
    if (sched_setscheduler (0, policy, &p))
        DEATH ("sched_setscheduler:");
    printf ("p.sched_priority = %d\n", p.sched_priority);
    exit (0);
}