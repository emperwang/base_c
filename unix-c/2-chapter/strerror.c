#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * strerror 函数能把错误号转变为出错信息
 * perror 函数打印出错信息
 *
 */
int main(int argc, char*argv[]){

	fprintf(stderr,"EACCES:%s\n", strerror(EACCES));
	errno=ENOENT;
	perror(argv[0]);
	exit(0);
}
