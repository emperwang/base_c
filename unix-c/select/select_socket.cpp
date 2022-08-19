#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#define INVALIDE_FD -1

void initialize(int* listenfd)
{
     // create a new socket
    *listenfd = socket(AF_INET, SOCK_STREAM, 0);
    int val=1;
    setsockopt(*listenfd, SOL_SOCKET, SO_REUSEADDR,&val, sizeof(val));
}

int bindaddr(int* listenfd)
{
    /*
    struct sockaddr_in
    {
        __SOCKADDR_COMMON (sin_);
        in_port_t sin_port;                 // Port number
        struct in_addr sin_addr;            // Internet address.

        // Pad to size of `struct sockaddr'.
        unsigned char sin_zero[sizeof (struct sockaddr) -
                            __SOCKADDR_COMMON_SIZE -
                            sizeof (in_port_t) -
                            sizeof (struct in_addr)];
    };
    typedef uint32_t in_addr_t;
    struct in_addr
    {
        in_addr_t s_addr;
    };
  */
    // initialize server address
    struct sockaddr_in bindaddr;
    memset(&bindaddr, 0, sizeof(bindaddr));
    bindaddr.sin_family = AF_INET;
    //bindaddr.sin_addr.s_addr = INADDR_ANY;
    bindaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bindaddr.sin_port = htons(10000);

    if(bind((*listenfd), (struct sockaddr *)&bindaddr, sizeof(bindaddr)) == -1)
    {
        int error = errno;
        std::cout<< "bind listenfd failed. errno: "<< error<< std::endl;
        perror("error: ");
        close((*listenfd));
        return -1;
    }
    return 0;
}

int listensocket(int* listenfd)
{

    // start listen
    if(listen((*listenfd), SOMAXCONN) == -1)
    {
        std::cout<< "listen error." << std::endl;
        close((*listenfd));
        return -1;
    }

    return 0;
}

void setreadset(int* listenfd,fd_set& readset,int& maxfd, std::vector<int>& clientfds)
{
    FD_ZERO(&readset);

    // set listenfd into readset
    FD_SET((*listenfd), &readset);



    // add clientfd into readset
    for(int i=0; i< clientfds.size(); i++)
    {
        if(clientfds[i] != INVALIDE_FD)
        {
            FD_SET(clientfds[i], &readset);

            if(maxfd < clientfds[i])
            {
                maxfd = clientfds[i];
            }
        }
    }
}

/*    nc [option] host port
 * test command:  nc  127.0.0.1 10000    // connect to server
 */
// use c++, because i want to use STD library.
int main(int argc, char *argv[])
{
   int listenfd;
   initialize(&listenfd);
   if(listenfd == INVALIDE_FD)
    {
        std::cout<<("create listen socket failed.") << std::endl;
        return -1;
    }

    if(bindaddr(&listenfd) < 0)
    {
        return -1;
    }

    if(listensocket(&listenfd) < 0)
    {
        return -1;
    }

    // storage receive client key
    std::vector<int> clientfds;
    int maxfd;
    maxfd = listenfd;
    while(true)
    {
        fd_set readset;
        setreadset(&listenfd,readset, maxfd,clientfds);
        timeval tm;
        tm.tv_sec = 1;
        tm.tv_usec = 0;

        // check read event, dont check write and exception event for now;
        int ret = select(maxfd+1, &readset, NULL, NULL, &tm);
        // error
        if(ret == -1)
        {
            // interrupt by single
            if(errno != EINTR)
            {
                break;
            }
        }else if(ret == 0) // no event
        {
            continue;
        }else {
            // receive read event, socket event
            if(FD_ISSET(listenfd, &readset))
            {
                struct sockaddr_in  clientaddr;
                socklen_t addrlen = sizeof(clientaddr);
                // receive client
                int clientfd = accept(listenfd,(struct sockaddr *)&clientaddr,&addrlen);
                if(clientfd == INVALIDE_FD)
                {
                    // reiceve socket error
                    break;
                }

                // receive socket, not receive data
                std::cout << "accept a client connection, fd: " << clientfd << std::endl;
                clientfds.push_back(clientfd);
            }else {
                // check client receive event
                char recvbuf[4096];
                int clentfdslength = clientfds.size();
                for(int i=0; i< clentfdslength; i++)
                {
                    if(clientfds[i] != INVALIDE_FD && FD_ISSET(clientfds[i],&readset))
                    {
                        memset(recvbuf, 0, sizeof(recvbuf));
                        //receive client data
                        // 接收数据返回0, 表明对端关闭了连接
                        int datalength = recv(clientfds[i],recvbuf,4096, 0);
                        if(datalength < 0)
                        {
                            std::cout << "recv data error, clientfd = " << clientfds[i] << std::endl;
                            close(clientfds[i]);
                            // mark the fd as invalid_fd
                            clientfds[i] = INVALIDE_FD;
                            continue;
                        }

                        if(datalength == 0)
                        {
                            std::cout << "client close, clientfd = " << clientfds[i] << std::endl;
                            close(clientfds[i]);
                            // mark the fd as invalid_fd
                            clientfds[i] = INVALIDE_FD;
                            continue;
                        }

                        std::cout << "clientfd " << clientfds[i] << ", receive data: " << recvbuf << std::endl;
                    }
                }
            }
        }
    }

    // close all socket
    for (int i= 0; i< clientfds.size(); i++)
    {
        if(clientfds[i] != INVALIDE_FD)
        {
            close(clientfds[i]);
        }
    }

    close(listenfd);
    return 0;
}



