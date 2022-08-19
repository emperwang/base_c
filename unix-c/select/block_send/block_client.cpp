#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // create socket
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if(clientfd < 0)
    {
        std::cout << "Create client fd error. errno: " << errno << std::endl;
        perror("clientfd error: ");
        return -1;
    }

    // connect to server
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveraddr.sin_port = htons(3000);
    int serveraddrlength = sizeof(serveraddr);
    if(connect(clientfd, (struct sockaddr *)&serveraddr, serveraddrlength) < 0)
    {
        std::cout << "connect to server error. errno: "<<errno <<std::endl;
        perror("connect failed: ");
        return -1;
    }

    #define DATA   "hello world"
    #define DATALEN  strlen(DATA)

    int count = 0;
    while(true)
    {
        // send will block until the buffer full
        int ret = send(clientfd, DATA, DATALEN,0);
        if (ret != DATALEN)
        {
            std::cout << "send error. errno: "<< errno <<std::endl;
            perror("send error: ");
           break;
        }else {
            count++;
            std::cout << "send success, count: "<< count << std::endl;
        }
        //sleep(1);
    }

    close(clientfd);

    return 0;
}


