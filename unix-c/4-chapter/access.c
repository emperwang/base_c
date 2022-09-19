#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * 使用access函数文件的 读写执行权限
 */
int main(int argc, char*argv[]){

	if (argc != 2){
		perror("usage : a.out <pathname>");
		exit(1);
	}

	if(access(argv[1], R_OK) < 0){
		printf("access error for %s\n", argv[1]);
		exit(2);
	}else{
		printf("read access OK\n");
	}

	if(open(argv[1], O_RDONLY)<0){
		printf("open error for %s",argv[1]);
	}else{
		printf("open for reading OK\n");
	}

	return 0;
}
