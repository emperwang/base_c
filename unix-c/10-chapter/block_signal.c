#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_quit(int);


int main(void){
	
	sigset_t  newmask, oldmask, pendmask;
	if(signal(SIGQUIT, sig_quit) == SIG_ERR){
		perror("can't catch SIGQUIT");
	}
	// init sig_set
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
	// 设置信号屏蔽字
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
		perror("SIG_BLOCK error");
	}

	sleep(5);
	// 获取未决信号
	if(sigpending(&pendmask) < 0){
		perror("sigpending error");
	}
	if(sigismember(&pendmask, SIGQUIT)){
		printf("\nSIGQUIT pending\n");
	}

	// restore signal mask
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		printf("SIG_SETMASK error");
	}
	printf("SIGQUIT unblocked\n");

	sleep(5);
	exit(0);
}

static void sig_quit(int signo){
	printf("catch SIGQUIT\n");
	if(signal(SIGQUIT, SIG_DFL) == SIG_ERR){
		perror("can't reset SIGQUIT");
	}

}
