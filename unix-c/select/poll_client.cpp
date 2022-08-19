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

int main(int argc,char** argv)
{
    // sokcet
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientfd < 0)
    {
        std::cout << "clientfd create errot. errno:"<<errno << std::endl;
        perror("client fd error: ");
        return -1;
    }

    int oldsocketopt = fcntl(clientfd, F_GETFL, 0);
    oldsocketopt |= O_NONBLOCK;
    if(fcntl(clientfd, F_SETFL, oldsocketopt) < 0)
    {
        std::cout << "nonblock errot. errno:"<<errno << std::endl;
        perror("nonblock error: ");
        return -1;
    }

    // server address
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3000);

    // connect to server
    for(;;)
    {
        int ret = connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        if(ret == 0)
        {
            std::cout << "connect to server successfully." << std::endl;
            //close(clientfd);
            //return -1;
            break;
        }else if(ret == -1)
        {
            if (errno == EINTR)
            {
                std::cout << "connecting interrupt by signal." << std::endl;
                continue;
            }
            else if(errno == EINPROGRESS)
            {
                std::cout << "connecting.."<< std::endl;
                break;
            }else // error
            {
                close(clientfd);
                return -1;
            }
        }

    }

    pollfd clientevent;
    clientevent.fd = clientfd;
    clientevent.events = POLLOUT;
    clientevent.revents = 0;

    if (poll(&clientevent,1, 1000) != 1)
    {
        close(clientfd);
        std::cout << "(poll) connect to server error" <<std::endl;
        return -1;
    }

    if(!(clientevent.revents & POLLOUT))
    {
        close(clientfd);
        std::cout << "(pollout) connect to server error" <<std::endl;
        return -1;
    }

    int err;
    socklen_t len = static_cast<socklen_t>(sizeof(err));

    if(getsockopt(clientfd, SOL_SOCKET, SO_ERROR, &err, &len) < 0)
    {
        return -1;
    }

    if(err == 0)
    {
        std::cout << "connect to server successfully." << std::endl;
    }else
    {
        std::cout << "connect to server failed." <<std::endl;
    }

    close(clientfd);
    return 0;
}

