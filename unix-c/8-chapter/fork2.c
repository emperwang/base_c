#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork error");
	}else if(pid = 0){	// first child
		if ((pid = fork())<0){ // fork child 
			perror("fork child error\n");
		}else if(pid > 0){	// first child
			printf("first child exiting...\n");
			exit(0);
		}
		// second child
		sleep(2);
		printf("seconds child, parent pid = %d\n", getppid());
		exit(0);
	}
	if(waitpid(pid, NULL ,0) != pid) {// wait for first child
		perror("waitpid error -- parent : ");
	}
	//parent exit
	exit(0);
}
