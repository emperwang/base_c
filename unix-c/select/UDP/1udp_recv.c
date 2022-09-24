#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
    // create socket
    int sfd = socket(AF_INET, SOCK_DGRAM,0);
    if(sfd < 0)
    {
        perror("create socket failed.\n");
        exit(1);
    }
    // bind
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    inet_pton(AF_INET,"127.0.0.1", &addr.sin_addr);

    // set options
    int on = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEPORT,&on, sizeof(on));
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR,&on, sizeof(on));

    if(bind(sfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind socket failed.\n");
        exit(2);
    }
    // recv msg
    struct sockaddr_in caddr;
    socklen_t addrlen = sizeof(caddr);
    char buf[1024];
    for(;;)
    {
        // ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                        //struct sockaddr *src_addr, socklen_t *addrlen);
        memset(buf, 0, sizeof(buf));
        printf("waitting for recv msg\n");
        fflush(stdout);
        int count = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&caddr, &addrlen);
        if(count < 0)
        {
            perror("read failed.\n");
            continue;
        }
        if(count > 0)
        {
            char ip[16];
            inet_ntop(AF_INET,&caddr.sin_addr,ip, sizeof(ip));
            write(STDOUT_FILENO,ip, 16);
            printf("recvfrom from: %s ",  buf);
            // send back to peer
            sendto(sfd, buf, count,0,(struct sockaddr *)&caddr, sizeof(caddr));
        }
    }

    close(sfd);
}

