#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * 获取进程的id号
 */
int main(){

	printf("process ID:%d\n", getpid());
	return 0;
}

