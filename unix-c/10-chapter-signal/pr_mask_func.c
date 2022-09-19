#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

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
			printf(" SIGINT");
		}

		if(sigismember(&sigset,SIGQUIT)){
			printf(" SIGQUIT");
		}

		if(sigismember(&sigset, SIGUSR1)){
			printf(" SIGUSR1");
		}

		if(sigismember(&sigset, SIGALRM)){
			printf(" SIGALRM");
		}
		printf("\n");
	}
	errno = errno_save;
}
