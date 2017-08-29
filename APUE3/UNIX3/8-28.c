#include "apue.h"

int main(void)
{
    pid_t   pid;
    
    printf("ppid = %ld\n", (long)getpid());   
    if ((pid = fork()) < 0)
      err_sys("fork error");
    else if(pid != 0)
    {
	printf("ppid1 = %ld\n", (long)getpid());   
        sleep(2);
        exit(2);
    }else{
	printf("pid1 = %ld\n", (long)getppid());
	}

    if ((pid = fork()) < 0)
      err_sys("fork error");
    else if (pid != 0)
    {
	printf("ppid2 = %ld\n", (long)getpid());
        sleep(4);
        abort();
    }else{
	printf("pid2 = %ld\n", (long)getppid());
	}

    if((pid = fork()) < 0)
      err_sys("fork error");
    else if (pid != 0)
    {
	printf("ppid3 = %ld\n", (long)getppid());
       execl("/bin/dd", "dd", "if=/etc/passwd", "of=/dev/null", NULL);
        exit(7);
    }else{
	printf("pid3 = %ld\n", (long)getpid());
	}

    if ((pid = fork()) < 0)
      err_sys("fork error");
    else if (pid != 0)
    {
	printf("ppid4 = %ld\n", (long)getppid());
        sleep(8);
        exit(0);
    }else{
	printf("pid4 = %ld\n", (long)getpid());
	}
    sleep(6);
    printf("pid5 = %ld\n", (long)getppid());
    kill(getpid(), SIGKILL);
    printf("pid6 = %ld\n", (long)getpid());
    exit(6);
}
