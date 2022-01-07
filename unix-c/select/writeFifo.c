#include <sys/select.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	int ret;
	ret = mkfifo("test_fifo",0666);
	if(ret != 0){
		perror("mkfifo:");
	}

	int fd;
	fd = open("test_fifo", O_RDWR);
	if(fd < 0){
		perror("open fifo");
		return -1;
	}

	while(1){
		char *str = "this is for test";
		write(fd, str, strlen(str));
		printf("after write to fifo\n");
		sleep(5);
	}

	return 0;
}
