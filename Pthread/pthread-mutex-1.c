#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define NUMS 10			//表示生产，消费的次数
#define CAPACITY 5		//定义缓冲区最大值
int capacity = 0;		//当前缓冲区的产品个数
pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;	//互斥量

void *produce(void *args)
{
    int i = 0;
    for (; i < NUMS;) {
	pthread_mutex_lock(&mylock);	//加锁
	if (capacity >= CAPACITY)	//当前产品个数大于等于缓冲区最大值，则不把产品放入缓冲区。
	{
	    printf("缓冲区已满，无法放入产品\n");
	} else {		//将产品放入缓冲区
	    ++capacity;
	    printf("生产者存入一个产品, 缓冲区大小为:%d\n",capacity);
	    i++;
	}
	pthread_mutex_unlock(&mylock);
    }
    return ((void *) 0);
}

void *consume(void *args)
{
    int i = 0;
    for (; i < NUMS;) {
	pthread_mutex_lock(&mylock);
	if (capacity > 0) {
	    --capacity;
	    printf("消费者消耗一个产品,缓冲区大小为:%d\n",capacity);
	    i++;
	} else {
	    printf("缓冲区已空，无法消耗产品\n");
	}
	pthread_mutex_unlock(&mylock);
    }
    return ((void *) 0);
}

int main(int argc, char **argv)
{

    int err;
    pthread_t produce_tid, consume_tid;
    void *ret;
    err = pthread_create(&produce_tid, NULL, produce, NULL);	//创建线程
    if (err != 0) {
		printf("线程创建失败:%s\n", strerror(err));
		exit(-1);
    }
    err = pthread_create(&consume_tid, NULL, consume, NULL);
    if (err != 0) {
		printf("线程创建失败:%s\n", strerror(err));
		exit(-1);
    }
    err = pthread_join(produce_tid, &ret);	//主线程等到子线程退出
    if (err != 0) {
		printf("生产着线程分解失败:%s\n", strerror(err));
		exit(-1);
    }
    err = pthread_join(consume_tid, &ret);
    if (err != 0) {
		printf("消费者线程分解失败:%s\n", strerror(err));
		exit(-1);
    }
    return (EXIT_SUCCESS);
}
