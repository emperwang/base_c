#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
/**
 *
 * 创建一个子进程，并在父进程中回收子进程
 *
 */
int main(){

	pid_t pid;
	int status;

	pid=fork();
	if(pid < 0){
		perror("fork error");
		exit(127);
	}else if(pid == 0){  // child
		// int execl(const char *path, const char *arg, ...);
		// 参数最后需要以 NULL 结尾; 注意点: 函数名中带 p, 说明会使用path环境变量
		//execl("/bin/ls","ls", "-l", "/home", NULL);

		// int execlp(const char *file, const char *arg, ...);
		execlp("ls", "ls", "-l", "/home", NULL);
		printf("exec ls cmd, child ID:%d, parent ID:%d\n",getpid(),getppid());
	}else if(pid > 0){ // parent
		printf("parent ID:%d\n", getpid());
		if((pid = waitpid(pid, &status,0)) < 0){
			printf("waitpid error\n");
		}
	}


	return 0;
}
