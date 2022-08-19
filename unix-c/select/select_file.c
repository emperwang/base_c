#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char*argv[]){
	fd_set rfds;
	struct timeval tv;
	int ret;
	int fd;

	ret = mkfifo("test_fifo",0666);
	if(ret != 0){
		perror("mkfifo:errpr: ");
	}

	fd = open("test_fifo", O_RDWR);
	if(fd < 0){
		perror("open fifo");
		return -1;
	}

	ret = 0;

	while(1){
		// 描述如0   以及 fifo加入集合
		FD_ZERO(&rfds);
		FD_SET(0, &rfds);
		FD_SET(fd,&rfds);
		// 超时设置
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		// 监控等待多个文件(标准输入和有名管道) 描述符的属性变化
		// 没有属性变化，此函数会阻塞，直到有变化才往下执行，这里没有设置超时
		// FD_SETSIZE 为 select.h 的宏定义， 为1024
		ret = select(FD_SETSIZE, &rfds, NULL, NULL, NULL);

		if(ret == -1){
			perror("select ()");
		}else if(ret > 0){
			char buf[1024] = {0};
			if(FD_ISSET(0, &rfds)) { // 标准输入
				read(0, buf, sizeof(buf));
				printf("stdin buf = %s ", buf);
			}else if(FD_ISSET(fd, &rfds)){
				read(fd, buf, sizeof(buf));
				printf("fifo buf = %s\n", buf);
			}
		}else if(0 == ret){
			printf("time out\n");
		}

	}

	return 0;
}
