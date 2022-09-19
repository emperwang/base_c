#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

volatile sig_atomic_t quitflag;

static void sig_int(int signo){

	if(signo == SIGINT){
		printf("\n Interrupt\n");
	}else if (signo == SIGQUIT){
		quitflag = 1;
	}
}

int main(){

	sigset_t newmask, oldmask,zeromask;
	if(signal(SIGINT, sig_int) == SIG_ERR){
		perror("signal(SIGINT) error");
	}

	if(signal(SIGQUIT, sig_int) == SIG_ERR){
		perror("signal(SIGQUIT) error");
	}

	sigemptyset(&zeromask);
	sigemptyset(&newmask);

	sigaddset(&newmask, SIGQUIT);
	// block SIGQUIT and save current signal mask
	if(sigprocmask(SIG_BLOCK,&newmask, &oldmask) < 0){
		perror("SIG_BLOCK  error");
	}

	while(quitflag == 0){
		sigsuspend(&zeromask);
	}

	quitflag = 0;
	// reset signal mask
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
		perror("SIG_SETMASK error");
	}

	exit(0);
}
