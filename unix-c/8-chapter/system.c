#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void pre_exit(int status){
	if(WIFEXITED(status)){
		printf("normal termination , exit status=%d\n", WEXITSTATUS(status));
	}else if(WIFSIGNALED(status)){
		printf("abnormal termination, signal number=%d , %s\n",WTERMSIG(status),
		#ifdef WCOREDUMP
			WCOREDUMP(status)?"core file generated":"");
		#else
			"");
		#endif
	}else if(WIFSTOPPED(status)){
			printf("child stopped, signal number =%d\n", WSTOPSIG(status));
			}
}



// 使用system调用系统cmd
int main(){
	
	int status;

	if((status = system("date")) <0 ){
		perror("system date error");
	}
	pre_exit(status);
	
	if((status = system("nosuchcommand")) < 0){
		perror("nosuch command error\n");
	}
	pre_exit(status);


	if((status = system("who; exit 44")) < 0){
		perror("system() who error");
	}
	pre_exit(status);


	exit(0);
}
