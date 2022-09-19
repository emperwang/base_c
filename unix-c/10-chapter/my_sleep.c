#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


// 信号处理函数
static void sig_alrm(int signo){
	// do nothing, just wake up the pause
}

// 自定义睡眠函数
unsigned int sleep1(unsigned int seconds){

	if(signal(SIGALRM, sig_alrm) == SIG_ERR){
		return seconds;
	}

	alarm(seconds);
	pause();
	return(alarm(0));
}

int main(){

	int i;

	int ret;

	for(i=0; i<10; i++){

		ret = sleep1(2);
		printf("%d\n", ret);
	}

	exit(0);
}



