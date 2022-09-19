#include <stdio.h>

/**
 * 从终端读取数据  然后输出到终端
 */
int main(){

	int c;
	while((c = getc(stdin))!= EOF){
		if (putc(c ,stdout) == EOF){
			perror("output error");
		}
	}

	if(ferror(stdin)){
		perror("input error");
	}

	return 0;
}


