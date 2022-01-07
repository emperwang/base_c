#include <stdio.h>
#include <unistd.h>

#define SIZE 8192
/**
 *从终端中读取数据并写入到终端
 */
int main(){
	
	int n;
	char buf[SIZE];

	while((n=read(STDIN_FILENO,buf,SIZE))>0){
		if(write(STDOUT_FILENO,buf,n) != n){
			perror("write error");
		}
	}
	
	if(n <0){
		perror("read error");
	}


	return 0;
}
