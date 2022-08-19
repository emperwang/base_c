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
#include <poll.h>
#include <fcntl.h>

/**
 *  struct pollfd {
 *      int fd;         // file descriptor
 *      short events;   // interested event
 *      short revents; //  received event
 * }
 */
#define INVALID_FD    -1
int main(int argc, char *argv[])
{
    // create fd
    int listened = socket(PF_INET, SOCK_STREAM, 0);
    if(listened == INVALID_FD)
    {
        std::cout << "create listen fd failed. errno: " << errno << std::endl;
        perror("listened fd failed: ");
        return -1;
    }

    // set nonblock
    int oldsocketopt = fcntl(listened, F_GETFL, 0);
    oldsocketopt = oldsocketopt | O_NONBLOCK;
    if(fcntl(listened, F_SETFL, oldsocketopt) < 0)
    {
        std::cout << "nonblock failed. errno: " << errno << std::endl;
        perror("nonblock failed: ");
        return -1;
    }

    // reuse port and address
    int cnt = 1;
    setsockopt(listened,SOL_SOCKET,SO_REUSEADDR,&cnt, sizeof(cnt));
    setsockopt(listened,SOL_SOCKET,SO_REUSEPORT, &cnt, sizeof(cnt));

    // get server address
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3000);

    // bind
    if(bind(listened, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        close(listened);
        std::cout << "bind failed. errno: " << errno << std::endl;
        perror("bind failed: ");
        return -1;
    }

    // listen

    if(listen(listened, SOMAXCONN) < 0)
    {
        close(listened);
        std::cout << "listen failed. errno: " << errno << std::endl;
        perror("listen failed: ");
        return -1;
    }

    std::vector<pollfd> fds;
    pollfd listenpollfd;
    listenpollfd.fd = listened;
    listenpollfd.events = POLLIN;
    listenpollfd.revents = 0;

    fds.push_back(listenpollfd);

    // if exists  invalid fd
    bool exists_invalid_fd = false;
    int n;
    while(true)
    {
        exists_invalid_fd = false;
        n = poll(&fds[0], fds.size(),1000);
        if( n < 0 )
        {
            if(errno == EINTR)
            {
                std::cout << "interrupt by signal" << std::endl;
                continue;
            }else
            {
                std::cout << "error" <<std::endl;
                break;
            }
        }else if (n == 0)
        {
            // timeout
            std::cout << "timeout."<<std::endl;
            continue;
        }

        for(int i=0; i<fds.size(); i++)
        {
            if(fds[i].revents & POLLIN)
            {
                if (fds[i].fd == listened)
                {
                    // receive socket
                    struct sockaddr_in clientaddr;
                    socklen_t addrlen = sizeof(clientaddr);
                    int clientfd = accept(fds[i].fd, (struct sockaddr*)&clientaddr, &addrlen);
                    if(clientfd < 0)
                    {
                        close(clientfd);
                        std::cout << "clientfd. errno: " << errno << std::endl;
                        perror("clientfd failed: ");
                    }else
                    {
                        // set client nonblock
                        int oldsocketopt = fcntl(clientfd, F_GETFL, 0);
                        oldsocketopt |= O_NONBLOCK;
                        if(fcntl(clientfd, F_SETFL, oldsocketopt) < 0)
                        {
                            close(clientfd);
                            std::cout << "nonblock. errno: " << errno << std::endl;
                        }else
                        {
                            struct pollfd clientpollfd;
                            clientpollfd.fd = clientfd;
                            clientpollfd.events = POLLIN;
                            clientpollfd.revents = 0;
                            fds.push_back(clientpollfd);
                            std::cout << "new client accept, client: " << clientfd << std::endl;
                        }
                    }
                }else   // client read event
                {
                    // read client data
                    char recvbuf[1024] = {0};
                    int num = recv(fds[i].fd, recvbuf, 1024,0);
                    if(num <= 0)
                    {
                        // error or peer close socket
                        if(errno != EINTR && errno != EWOULDBLOCK)
                        {
                            for(std::vector<pollfd>::iterator it = fds.begin(); it != fds.end(); it++)
                            {
                                if(it->fd == fds[i].fd)
                                {
                                    std::cout << "client disconnect, clientfd : " << fds[i].fd << std::endl;
                                    close(fds[i].fd);
                                    it->fd = INVALID_FD;
                                    exists_invalid_fd = true;
                                }
                            }
                        }
                    }
                    else   // receive data
                    {
                        std::cout << "receive data: " << recvbuf << std::endl;
                    }
                }
            } // POLLIN event
            else if(fds[i].revents & POLLERR)
            {
                // todo: error event process
            }
        }
        if(exists_invalid_fd)
        {
            // clear invalid socket
            for(std::vector<pollfd>::iterator it = fds.begin(); it != fds.end();)
            {
                if(it->fd == INVALID_FD)
                {
                    it = fds.erase(it);
                }else
                {
                    it++;
                }
            }
        }
    }

    // close client socket

    for(std::vector<pollfd>::iterator it = fds.begin(); it != fds.end(); it++)
    {
        close(it->fd);
    }

    close(listened);
    return 0;
}





