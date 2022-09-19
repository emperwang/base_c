#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char name[1024], line[1024];
	FILE *fp;
	// tmp file
	printf("%s \n", tmpnam(NULL));
	// tmp file
	tmpnam(name);

	if((fp = tmpfile()) == NULL){
		perror("tempfile error");
	}
	// write to tmp file
	fputs("one line if output\n",fp);
	// read back
	rewind(fp);

	if(fgets(line, sizeof(line), fp) == NULL){
		perror("fgets error");
	}
	fputs(line , stdout);
	sleep(100);
	exit(0);
}
