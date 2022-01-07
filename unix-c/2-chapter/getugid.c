#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * 获取执行程序的用户的用户id，组id
 *
 */
int main(int argc,char*argv[]){

	printf("uid=%d, gid=%d\n", getuid(), getgid());

	return 0;
}
