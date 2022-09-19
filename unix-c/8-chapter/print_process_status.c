#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
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

// 打印进程的退出状态
int main(){
	pid_t pid;
	int status;

	if((pid=fork()) < 0){
		perror("fork error");
	}else if(pid == 0){  // child
		exit(7);
	}
	// 父进程回收进程
	if(wait(&status) != pid){// wait for child
		perror("wait error\n");
	}
	pre_exit(status);

	// 再次创建进程
	if((pid = fork()) < 0){
		perror("fork error2");
	}else if(pid == 0){
		abort();  // abort 结束
	}
	// 父进程回收进程
	if(wait(&status) != pid){
		perror("wait error\n");
	}
	pre_exit(status);// 打印退出信息

	if((pid = fork())<0){
		perror("fork error3\n");
	}else if(pid == 0){
		status /= 0;		// 除0，产生SIGFPE 信号
	}
	if(wait(&status) != pid){
		perror("wait error\n");
	}
	pre_exit(status);

	exit(0);
}
