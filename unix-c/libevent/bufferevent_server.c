#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stddef.h>
#include <error.h>
#include <unistd.h>
#include <event.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <event2/listener.h>

// typedef void(* bufferevent_data_cb) (struct bufferevent *bev, void *ctx)
// typedef void(* bufferevent_event_cb) (struct bufferevent *bev, short what, void *ctx)
static void readcb(struct bufferevent *bev, void *ctx)
{
    char buf[1024] = {0};
    size_t n = bufferevent_read(bev, buf, sizeof(buf));
    fprintf(stdout,"receive client msg: %s\n", buf);

    bufferevent_write(bev, buf, sizeof(buf));
}

static void writecb(struct bufferevent *bev, void *ctx)
{
    struct evbuffer* buf = bufferevent_get_output(bev);
    if(evbuffer_get_length(buf) <= 0)
    {
        fprintf(stdout, "server flushed data.\n");
    }
}

static void eventcb(struct bufferevent *bev, short what, void *ctx)
{
    if(what & BEV_EVENT_EOF)
    {
        fprintf(stderr, "connection closed.\n");
    }else if(what & BEV_EVENT_ERROR)
    {
        fprintf(stderr, "got and error on the connection: %s\n", strerror(errno));
    }

    bufferevent_free(bev);
}

// 侦听器 callback
static void connlistener_cb (struct evconnlistener* listener, evutil_socket_t cfd, struct sockaddr *cliaddr, int socklen, void* ptr)
{
    struct event_base* base = (struct event_base*) ptr;
    // create bufferevent
    struct bufferevent *bev = bufferevent_socket_new(base, cfd, BEV_OPT_CLOSE_ON_FREE);
    if(!bev)
    {
        fprintf(stderr, "constructing bufferevent failed.");
        return ;
    }
    // set bufferevent callback
    bufferevent_setcb(bev,readcb, writecb, eventcb, base);

    // enable event
    bufferevent_enable(bev, EV_READ|EV_WRITE);

    // disable event
    //bufferend_disable(bev, EV_READ|EV_WRITE);
}

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    // create socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    addr.sin_port = htons(8888);
    socklen_t len = sizeof(addr);
    /*int lfd  = Socket((struct sockaddr*)&addr);
     */
    /*int on = 1;
    int lfd = socket(AF_INET, SOCK_STREAM,0);
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
    setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, (char *)&on, sizeof(on));
    if(bind(lfd, (struct sockaddr*)&addr, len) < 0)
    {
        perror("Create socket error.\n");
        _exit(-1);
    }

     if(listen(lfd, 128) < 0)
    {
        perror("listener fd error.\n");
        _exit(-1);
    }*/

    // create event_base
    struct event_base *base = event_base_new();

    // 使用侦听器创建socket server
    struct evconnlistener* listener = evconnlistener_new_bind(base, connlistener_cb, base, LEV_OPT_CLOSE_ON_FREE|LEV_OPT_REUSEABLE, 128,
                                        (struct sockaddr*)&addr, len);

    fprintf(stdout, "server started\n");
    // start eventlopp
    event_base_dispatch(base);

    // free resource
    event_base_free(base);

    return 0;
}