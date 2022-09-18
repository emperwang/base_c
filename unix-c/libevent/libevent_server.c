#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stddef.h>
#include <error.h>
#include <unistd.h>
#include <event.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int Socket(struct sockaddr* addr)
{
    int on = 1;
    int lfd = socket(AF_INET, SOCK_STREAM,0);
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
    setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
    socklen_t len = sizeof(*addr);
    if(bind(lfd, addr, len) < 0)
    {
        perror("Create socket error.\n");
        _exit(-1);
    }
    return lfd;
}

void Listen(int lfd)
{
    if(listen(lfd, 128) < 0)
    {
        perror("listener fd error.\n");
        _exit(-1);
    }
}

void client_read_write_cb(evutil_socket_t cfd, short events, void *arg)
{
    char buf[1024] = {0};
    printf("client read write event: 0x%x \n", events);
    struct event *self = (struct event *)arg;
    if(events & EV_READ)
    {
        int n = recv(cfd, buf, sizeof(buf),0);
        printf("client read event: %s\n", buf);
        if(n <= 0) //有可读事件, 但是读取不到数据, 说明对端关闭了
        {
            printf("client disconnect");
            event_del(self);
            close(cfd);
        }else
        {
            send(cfd, buf, n,0);
        }
    }
}

// typedef void(* event_callback_fn) (evutil_socket_t, short, void *)
// 此处的lfd为监听fd
void listencb(evutil_socket_t lfd, short events, void *arg)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    // 提取 客户端fd
    int cfd  = accept(lfd, (struct sockaddr *)&addr, &len);
    char str[INET_ADDRSTRLEN];
    printf("receive client fd: %d, addr: %s, port: %d\n", cfd, inet_ntop(AF_INET,&addr.sin_addr,str,sizeof(str)), ntohs(addr.sin_port));
    struct event_base *base = (struct event_base*)arg;
    // 创建event 把此接收到的客户端cfd 注册到loop中
    // event_self_cbarg 把自己身作为参数
    struct event *cev = event_new(base, cfd, EV_PERSIST|EV_READ, client_read_write_cb, event_self_cbarg());
    if(event_add(cev,NULL) < 0)
    {
        perror("add client event failed.\n");
    }
}

int main()
{
    setbuf(stdout, NULL);
    // create socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    addr.sin_port = htons(8888);

    /*int lfd  = Socket((struct sockaddr*)&addr);
     */
    int on = 1;
     int lfd = socket(AF_INET, SOCK_STREAM,0);
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
    setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
    socklen_t len = sizeof(addr);
    if(bind(lfd, (struct sockaddr*)&addr, len) < 0)
    {
        perror("Create socket error.\n");
        _exit(-1);
    }

     if(listen(lfd, 128) < 0)
    {
        perror("listener fd error.\n");
        _exit(-1);
    }
    // create event_base
    struct event_base *base = event_base_new();
    // create event
    // 参数: base,监听的的socket文件描述符, 接收回调函数,  回调函数的参数
    struct event *ev = event_new(base, lfd,EV_PERSIST|EV_READ, listencb, base);
    // add event to event_base
    if(event_add(ev, NULL) < 0)
    {
        perror("add event failed. \n");
        _exit(-2);
    }
    // event_loop
    printf("server started\n");
    event_base_dispatch(base);
    // free resources

    close(lfd);
    event_base_free(base);

    return 0;
}