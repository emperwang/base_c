#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_int(int signo){
	printf("process signal....\n");
}

int main(int argc, char*argv[]){
	// 注册处理函数
	if(signal(SIGINT, sig_int) == SIG_ERR){
		perror("register func error");
	}

	while(1){
		printf("main outputing\n");
		sleep(2);
	}
	return 0;
}
