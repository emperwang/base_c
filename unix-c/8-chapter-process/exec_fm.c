#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *env_init[] = {"USER=unknown","HELLO=WORKLD",NULL};

int main(){
	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork error");
	}else if(pid == 0){ // specify pathname, specify envir
		if(execle("/bin/ls","lh","/", (char *)0, env_init) <0){
			perror("execle error");
		}
	}

	if(waitpid(pid, NULL ,0) < 0){
		perror("waitpid error\n");
	}

	printf("---------------------------------------------\n");

	if((pid = fork()) < 0){
		perror("fork error");
	}else if(pid == 0){
		if (execlp("ls","-lh","/", (char*)0) < 0){
			perror("execlp error");
		}
	}

	exit(0);
}
