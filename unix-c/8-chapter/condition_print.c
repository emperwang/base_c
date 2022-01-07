#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static void charatatime(char *);

// 父子进程竞争输出信息
int main(){
	pid_t pid;

	if((pid = fork()) < 0){
		perror("fork error");
	}else if(pid == 0){
		charatatime("output from child\n");
	}else {
		charatatime("output from parent\n");
	}
	
	exit(0);
}


static void charatatime(char *str){
	
	char *ptr;
	int c;
	
	setbuf(stdout, NULL);
	for(ptr = str; (c = *ptr++) != 0;){
		putc(c, stdout);
	}
}
