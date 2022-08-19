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
    // clientfd create
    int clientfd = socket(AF_INET, SOCKET_STREAM,0);
    if(clientfd < 0 )
    {
        std::cout << "create socket failed. errno: " <<errno << std::endl;
        perror("socketfd failed: ");
        return -1;
    }
    // service address
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3000);
    // connect
    if(connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        std::cout << "connect failed. errno: " <<errno << std::endl;
        perror("connect failed: ");
        return -1;
    }

    char revbuf[1024] = {0};
    int ret = recv(clientfd, revbuf, sizeof(revbuf), 0);
    if(ret > 0)
    {
        std::cout << "receive success :" << revbuf << std::endl;
    }else
    {
        std::cout << "receive error."<<std::endl;
    }

    close(clientfd);
    return 0;
}