#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globval = 6;

/**
 * vfork 使用。其与fork最大区别是vfork保证了子进程先执行
 */
int main(){
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork\n");

	if((pid = vfork())<0){
		perror("vfork error\n");
	}else if(pid == 0){ // child
		printf("child process\n");
		globval++;
		var++;
		_exit(0);
	} 
	// parent
	printf("pid=%d, glob=%d, var=%d\n", getpid(), globval,var);

	exit(0);
}
