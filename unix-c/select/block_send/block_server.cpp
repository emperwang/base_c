#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    // create a listenfd
    int listenfd = socket(AF_INET, SOCK_STREAM,0);
    if(listenfd < 0)
    {
        std::cout << "create listenfd error. "<<std::endl;
        return -1;
    }

    // initialize server address
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3000);

    if(bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        std::cout << "bind address error, errno = "<< errno <<std::endl;
        perror("bind error: ");
        return -1;
    }

    // start listen
    if(listen(listenfd,SOMAXCONN) < 0)
    {
        std::cout << "start listening error, errno = "<<errno <<std::endl;
        perror("listen errror: ");
        return -1;
    }

    while(true)
    {
        struct sockaddr_in clientaddr;
        socklen_t clientaddr_len = sizeof(clientaddr);
        // accept client
        int clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddr_len);
        if(clientfd < 0)
        {
            std::cout << "receive client error" << std::endl;
            continue;
        }else {
            std::cout << "accept client: " << clientfd << std::endl;
        }
    }

    close(listenfd);
    return 0;
}