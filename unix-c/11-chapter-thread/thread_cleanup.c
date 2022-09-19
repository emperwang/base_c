#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void cleanup(void *arg){
	printf("cleanup:%s\n", (char*)arg);
}

void *thr_fn1(void *arg){
	printf("thread 1 start\n");
	pthread_cleanup_push(cleanup,"thread 1 first handler");
	pthread_cleanup_push(cleanup,"thread 1 seconds handler");
	printf("thread1 push complete \n");
	if(arg){ // 此种使用  return返回的则不会调用清理函数
		return ((void*)1);
	}
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return((void*)1);
}

void *thr_fn2(void *arg){
	printf("thread 2 start\n");
	// 注册清理函数
	pthread_cleanup_push(cleanup,"thread 2 first handler");
	pthread_cleanup_push(cleanup,"thread 2 seconds handler");
	printf("thread1 push complete \n");
	if(arg){ // 线程使用 pthread_exit 返回的才能调用清理函数
		pthread_exit((void*)1);
	}
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	pthread_exit((void*)2);
}


int main(){
	int err;
	pthread_t tid1, tid2;
	void *tret;

	err = pthread_create(&tid1, NULL,thr_fn1, (void*)1);
	if(err != 0){
		printf("can't create thread 1. err=%d\n", err);
	}

	err = pthread_create(&tid2,NULL, thr_fn2, (void*)1);
	if(err != 0){
		printf("can't create thread 2, err=%d\n", err);
	}

	err = pthread_join(tid1, &tret);
	if(err != 0){
		printf("can't join with thread 1, err=%d\n", err);
	}
	err = pthread_join(tid2, &tret);
	if(err != 0){
		printf("can't join with thread 2, err=%d\n", err);
	}

	printf("thread 2 exit code %ld\n", (long)tret);

	exit(0);
}



