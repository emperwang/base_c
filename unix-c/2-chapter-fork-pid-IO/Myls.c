#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
模拟ls，输入一个目录下的所有文件
 */
int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *dirp;
	
	if(argc != 2)
		perror("a single argument(the directory name) is required");

	if((dp = opendir(argv[1]))== NULL)
		printf("can't open %s", argv[1]);

	while((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}
