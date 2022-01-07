#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

static void sig_int(int);

void pr_mask(const char *str){
	sigset_t  sigset;
	int errno_save;

	errno_save = errno;
	// 获取信息屏蔽字
	if(sigprocmask(0,NULL,&sigset) < 0){
		perror("sigprocmask error");
	}else {
		printf("%s", str);
		
		if(sigismember(&sigset, SIGINT)){
			printf("  SIGINT");
		}

		if(sigismember(&sigset,SIGQUIT)){
			printf("  SIGQUIT");
		}

		if(sigismember(&sigset, SIGUSR1)){
			printf("  SIGUSR1");
		}

		if(sigismember(&sigset, SIGALRM)){
			printf("  SIGALRM");
		}
		printf("\n");
	}
	errno = errno_save;
}

// 保存临界区代码  不受信号的干扰
int main(){
	
	sigset_t newmask, oldmask, waitmask;

	pr_mask("program start:");
	
	if(signal(SIGINT, sig_int) == SIG_ERR){
		perror("signal(SIGINT) error");
	}

	sigemptyset(&waitmask);
	sigaddset(&waitmask, SIGUSR1);

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);

	// block SIGINT and save current  signal mask
	if(sigprocmask(SIG_BLOCK, &newmask,&oldmask) < 0){
		perror("SIG_BLOCK error");
	}

	// cirtical region of code
	pr_mask("in cirtical region");

	// pause allowing all signals  execpt SIGUSR1
	if(sigsuspend(&waitmask) != -1){
		perror("sigsuspend error");
	}

	pr_mask("after return from sigsuspend:");
	// reset signal mask  which unblocks SIGINT
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		perror("SIG_SETMASK error");
	}
	// continue processing
	pr_mask("program exit");

	exit(0);
}


static void sig_int(int signo){
	pr_mask("\n in sig_in:");
}



