#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * fork创建子进程。
 * 通过打印发现子进程只是父进程的副本，globvar全局变量和var局部变量不共享
 */
int globvar = 6;
char buf[] = "A write to stdout\n";
int main(){
	int var; // atomatic variable on the stack
	pid_t pid;

	var = 88;
	if(write(STDOUT_FILENO,buf, sizeof(buf)-1) != (sizeof(buf)-1)){
		perror("write to console error");
	}
	printf("before fork\n");
	
	if((pid = fork()) < 0){
		perror("fork error");
	}else if(pid == 0){
		printf("child process\n");
		globvar++;
		var++;
	}else {
		printf("parent process\n");
		sleep(5);  // wait child
	}
	printf("pid= %d, glob = %d, var=%d\n", getpid(), globvar, var);

	exit(0);
}
