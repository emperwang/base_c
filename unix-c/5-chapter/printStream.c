#include <stdio.h>
#include <stdlib.h>

void pr_stdio(const char *name, FILE *fp){

	printf("stream = %s ", name);

	if(fp->_flags & _IONBF)
		printf("unbuffered\n");
	else if(fp->_flags & _IOLBF)
		printf("line buffered\n");
	else
		printf("fully buffered\n");

	//printf(", buffer size =%d\n", fp->buflen);
}

/**
 * 判断一个流是不是缓存的
 */

int main(){
	FILE *fp;

	fputs("enter any character\n",stdout);
	if(getchar() == EOF){
		perror("getchar error");
	}
	fputs("one line to standard error\n", stderr);

	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr",stderr);

	if((fp = fopen("/etc/motd","r")) == NULL){
			perror("fopen error\n");
	}

	if(getc(fp) == EOF){
		perror("getc error\n");
	}

	pr_stdio("/etc/motd", fp);

	exit(0);
}
