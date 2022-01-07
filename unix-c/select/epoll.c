#include <stdio.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int ret;
	int fd;

	ret = mkfifo("test_fifo",0666);
	if(ret != 0){
		perror("mkfifo");
	}

	fd = open("test_fifo",O_RDWR);
	if(fd < 0){
		perror("open fifo");
		return -1;
	}

	ret = 0;
	struct epoll_event event;
	struct epoll_event wait_event;

	// 创建一个 epoll 的句柄， 参数要大于10，没有太大作用
	int epfd = epoll_create(10);
	if( -1 == epfd){
		perror("create epoll");
		return -1;
	}
	// 注册标准输入
	event.data.fd = 0;
	event.events = EPOLLIN;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &event);
	if(-1 == ret){
		perror("epoll_ctl");
		return -1;
	}
	// 注册管道
	event.data.fd = fd;
	event.events = EPOLLIN;
	// 事件注册函数，将有名管道描述符fd 加入监听事件
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
	if(-1 == ret){
		perror("fifo epoll ctl");
		return -1;
	}

	ret = 0;
	while(1){
		
		// 监控并等待多个文件描述符属性变化(是否可读)
		// 没有属性变化，这个函数会阻塞，直到有变化才往下执行，这里没有设置超时
		ret = epoll_wait(epfd, &wait_event, 2, -1);
		//ret = epoll_wait(epfd, &^wait_event,2, 1000);
		if(ret == -1){
			close(epfd);
			perror("epoll");
		}else if(ret > 0){
			char buf[1024] = {0};
			if (( 0 == wait_event.data.fd) && (EPOLLIN == wait_event.events & EPOLLIN)){
				read(0, buf, sizeof(buf));
				printf("stdin buf = %s \n", buf);
			}else if(( fd == wait_event.data.fd) && (EPOLLIN == wait_event.events & EPOLLIN)){
				read(fd, buf , sizeof(1024));
				printf("fifo  buf = %s\n", buf);
			}
		}else if(ret == 0){
			printf("time out\n");
		}
	}

	close(epfd);
	return 0;
}
