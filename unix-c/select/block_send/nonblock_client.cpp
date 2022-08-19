#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    // create socket
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientfd < 0)
    {
        std::cout << "create socket failed. errno: " <<errno << std::endl;
        perror("socketfd failed: ");
        return -1;
    }

    // server address
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3000);

    // connect to server
    if(connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        std::cout << "connect failed. errno: " <<errno << std::endl;
        perror("connect failed: ");
        return -1;
    }

    // set nonblock after connect success
    int oldsockopt = fcntl(clientfd, F_SETFL, 0);
    oldsockopt = oldsockopt | O_NONBLOCK;
    if(fcntl(clientfd, F_SETFL,oldsockopt) < 0)
    {
        close(clientfd);
        std::cout << "set nonblock failed. errno: " <<errno << std::endl;
        perror("set nonblock failed: ");
        return -1;
    }

    #define DATA   "hello world"
    #define DATALEN  strlen(DATA)
    // begin send data
    int cout = 0;

    while(true)
    {
        int ret = send(clientfd,DATA, DATALEN, 0);

        if (ret == -1)
        {
            // 飞阻塞模式下, tcp窗口太小, 发送失败
            if(errno == EWOULDBLOCK)
            {
                std::cout << "send failed caused by tcp windows too low."<<std::endl;
                perror("send failed: ");
                continue;
            }
            // interrupt by singal
            if(errno == EINTR)
            {
                std::cout << "interrupt by EINTR"<<std::endl;
                perror("interrupt: ");
                continue;
            }

            std::cout << "Send failed. errno :" <<errno<<std::endl;
            break;
        }
        else if(ret == 0)
        {
            // peer close socket
            std::cout << "send error. caused by closed by peer."<<std::endl;
            break;
        }else
        {
            std::cout << "send success. cout: "<< cout++ << std::endl;
        }

    }

    return 0;
}

