#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// 指向函数的指针，该函数要求一个整型参数，而且无返回值
/*#define  SIG_ERR (void (*)())-1
#define  SIG_DFL (void (*)())0
#define  SIG_IGN (void (*)())1 */

static void sig_usr(int signo);  // signal hanlder

int main(){

	if(signal(SIGUSR1, sig_usr) == SIG_ERR){// 为SIGUSR1 注册信号捕捉函数
		perror("can't catch SIGUSR1");
	}

	if(signal(SIGUSR2, sig_usr) == SIG_ERR){
		perror("can't catch SIGUSR2");
	}
	for(;;){
		pause();// 等待信号
	}

	exit(0);
}


static void sig_usr(int signo){

	if(signo == SIGUSR1){
		printf("received SIGUSR1\n");
	}else if(signo == SIGUSR2){
		printf("received SIGUSR2\n");
	}else {
		printf("received signal %d\n", signo);
	}
}
