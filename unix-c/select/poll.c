#include <poll.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	int ret ;
	int fd;

	struct pollfd fds[2];
	ret = mkfifo("test_fifo",0666);
	if(ret != 0){
		perror("mkfifo:");
	}

	fd = open("test_fifo", O_RDWR);
	if(fd < 0){
		perror("open fifo");
		return -1;
	}
	ret = 0;
	fds[0].fd = 0;
	fds[1].fd = fd;
	
	// 普通 或  优先级数据可读
	fds[0].events = POLLIN;
	fds[1].events = POLLIN;

	while(1){
		// 监控多个文件(标准输入，有名管道)描述符的属性变化（是否可读）
		// 没有属性变化，此函数会阻塞，直到有变化才往下执行，这里没有设置超时
		ret = poll(fds,2,-1);
		if(ret == -1){
			perror("poll");
		}else if(ret > 0){
			char buf[1024] = {0};
			if((fds[0].revents & POLLIN) == POLLIN){
				read(0, buf, sizeof(buf));
				printf("stdin buf = %s \n",buf);

			}else if((fds[1].revents & POLLIN) == POLLIN){
				read(fd, buf,sizeof(buf));
				printf("fifo buf = %s \n", buf);
			}
		}else if (0 == ret){
			printf(" time out\n");
		}
	}


	return 0;
}
