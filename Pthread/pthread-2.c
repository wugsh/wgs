#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include <stdio.h>

static void thread_one(char *msg);
static void thread_two(char *msg);
int main(int argc, char **argv)
{
    pthread_t th_one, th_two;
    char *msg = "thread";
    int res;
    printf("thread_one starting\n");
    res = pthread_create(&th_one, NULL, (void *) &thread_one, msg);
	if (res != 0) {
	exit(EXIT_FAILURE);
    }
	//sleep(1);//注释1
    printf("thread_two starting\n");
    res = pthread_create(&th_two, NULL, (void *) &thread_two, msg);
	if (res != 0) {
	exit(EXIT_FAILURE);
    }
//    sleep(5);//注释2
  //  printf("Main thread will sleep 1 S\n");
 //   sleep(1);			//注释3
    return 0;

}

static void thread_one(char *msg)
{
    int i = 0;
    while (i < 6) {
	printf("I am one. loop %d\n", i);
	i++;
//sleep(1);//注释4
    }
}

static void thread_two(char *msg)
{
    int i = 0;
    while (i < 6) {
	printf("I am two. loop %d\n", i);
	i++;
//sleep(1);//注释5
    }
}
