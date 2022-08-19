#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <vector>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct epoll_event
 * {
 * uint32_t  events;    // event
 * epoll_data_t data;   // user custom data
 * }
 *
 * typedef union epoll_data
 * {
 *  void*  ptr;
 *  int fd;
 * uint32_t  u32;
 * uint64_t  u64;
 * }epoll_data_t;
 */
int main(int argc, char* argv[])
{
    // create socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
    {
        std::cout << "listenfd create errot. errno:"<<errno << std::endl;
        perror("listenfd  error: ");
        return -1;
    }

    // reuse address and port
    int on = 1;
    setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on, sizeof(on));
    setsockopt(listenfd,SOL_SOCKET,SO_REUSEPORT, &on, sizeof(on));

    // set non block
    int oldsocketopt = fcntl(listenfd, F_GETFL, 0);
    oldsocketopt |= O_NONBLOCK;

    if(fcntl(listenfd, F_SETFL, oldsocketopt) < 0)
    {
        std::cout << "nonblock failed. errno: " << errno << std::endl;
        perror("nonblock failed: ");
        return -1;
    }

    // init server address
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3000);

    // bind
    if(bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        close(listenfd);
        std::cout << "bind failed. errno: " << errno << std::endl;
        perror("bind failed: ");
        return -1;
    }

    // listen
    if(listen(listenfd,SOMAXCONN) < 0)
    {
        close(listenfd);
        std::cout << "listen failed. errno: " << errno << std::endl;
        perror("listen failed: ");
        return -1;
    }

    // create epoll

    int epollfd = epoll_create(1);
    if(epollfd == -1)
    {
        close(listenfd);
        std::cout << "epollfd failed. errno: " << errno << std::endl;
        perror("epollfd failed: ");
        return -1;
    }

    epoll_event listenevent;
    listenevent.data.fd = listenfd;
    listenevent.events = EPOLLIN;

    // set ET mode
    //listenevent.events |= EPOLLET;

    // set listen fd
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &listenevent) == -1)
    {
        close(listenfd);
        std::cout << "epoll_ctl failed. errno: " << errno << std::endl;
        perror("epoll_ctl failed: ");
        return -1;
    }

    int n;
    while(true)
    {
        epoll_event epoll_events[1024];
        n = epoll_wait(epollfd, epoll_events, 1024, 1000);

        if(n < 0)
        {
            if(errno == EINTR)
            {
                std::cout << "interrupt by signal" <<std::endl;
                continue;
            }else {

                std::cout << "error. "<<std::endl;
                break;
            }
        }else if(n == 0)
        {
            // timeout
            std::cout << "timeout " << std::endl;
            continue;
        }

        for (int i=0; i< n; i++)
        {
            if(epoll_events[i].events & EPOLLIN) // read event
            {
                if(epoll_events[i].data.fd == listenfd)
                {
                    struct sockaddr_in  clientaddr;
                    socklen_t clientaddrlen = sizeof(clientaddr);
                    int clientfd = accept(epoll_events[i].data.fd, (struct sockaddr *)&clientaddr, &clientaddrlen);
                    if(clientfd != -1)
                    {
                        int oldsocketopt = fcntl(clientfd, F_GETFL, 0);
                        oldsocketopt |= O_NONBLOCK;
                        if(fcntl(clientfd, F_SETFL, oldsocketopt) < 0)
                        {
                            close(clientfd);
                            std::cout << "clientfd nonblock failed. errno: " << errno << std::endl;
                        }
                        else
                        {
                            epoll_event clienteventinfo;
                            clienteventinfo.data.fd = clientfd;
                            clienteventinfo.events = EPOLLIN;
                            //clienteventinfo.events = EPOLLET;

                            if(epoll_ctl(epollfd, EPOLL_CTL_ADD,clientfd, &clienteventinfo) != -1)
                            {
                                std::cout << "new client accepted, clientfd: " <<clientfd << std::endl;
                            }
                            else
                            {
                                std::cout << "new client register error, clientfd: " <<clientfd << std::endl;
                                close(clientfd);
                            }

                        }

                    }
                }
                else    // other client read event
                {
                    char ch;
                    int m = recv(epoll_events[i].data.fd, &ch,1,0);
                    if(m == 0)
                    {
                        // closed by peer
                        if(epoll_ctl(epollfd, EPOLL_CTL_DEL, epoll_events[i].data.fd, NULL) != -1)
                        {
                            std::cout << "client disconnected, clientfd: "<<epoll_events[i].data.fd << std::endl;
                        }
                    }
                    else if(m < 0)
                    {
                        if(errno != EWOULDBLOCK && errno != EINTR)
                        {
                            if(epoll_ctl(epollfd, EPOLL_CTL_DEL, epoll_events[i].data.fd, NULL) != -1)
                            {
                                std::cout << "client disconnected, clientfd: "<<epoll_events[i].data.fd << std::endl;
                            }
                        }
                        close(epoll_events[i].data.fd);
                    }
                    else    // normal receive data
                    {
                        std::cout << "receive from client: " << epoll_events[i].data.fd <<", data: "<<ch << std::endl;
                    }
                }
            } // read event
            else if(epoll_events[i].events & EPOLLERR)    // error event
            {
                // todo
                std::cout << "error event" <<std::endl;
            }
        }
    }

    close(listenfd);
    return 0;
}



