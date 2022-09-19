#include <stdio.h>
#include <stdlib.h>

static void my_exit1(void), my_exit2(void);

/**
 * 使用atexit注册结束函数
 */
int main(){
	if(atexit(my_exit2) != 0){
		perror("can't register my_exit2\n");
	}

	if(atexit(my_exit1) != 0){
		perror("can't register my_Exit1\n");
	}

	printf("main is done\n");

	return 0;
}

static void my_exit1(void){

	printf("first exit handler, exit1\n");
}

static void my_exit2(void){
	printf("seconds exit handler, exit2\n");
}
