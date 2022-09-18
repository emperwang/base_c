#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
/*
 #define UNIX_PATH_MAX    108

           struct sockaddr_un {
               sa_family_t sun_family;               // AF_UNIX
               char        sun_path[UNIX_PATH_MAX];  // pathname
           };
*/

int main(int argc, char *argv[])
{

    // 1. create socket
    int lfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(lfd < 0)
    {
        perror("create socket error\n");
        return -1;
    }

    struct sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path,"sock.s");

    socklen_t len = offsetof(struct sockaddr_un,sun_path) + strlen(addr.sun_path);

    if(bind(lfd,(struct sockaddr*)&addr, len) < 0)
    {
        perror("bind address failed. \n");
        return -2;
    }

    if(listen(lfd,128) < 0)
    {
        perror("listen address failed. \n");
        return -3;
    }
    setbuf(stdout, NULL);
    struct sockaddr_un clientaddr;
    socklen_t clen = sizeof(clientaddr);
    int cfd = accept(lfd, (struct sockaddr*)&clientaddr, &clen);
    if(cfd > 0)
    {
        printf("receive client: %d, path: %s\n", cfd, clientaddr.sun_path);
    }
    char buf[1024] = "";
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        int n = recv(cfd, buf, sizeof(buf), 0);
        printf("received from client: %s", buf);
        send(cfd, buf, n, 0);
        sleep(1);
    }

    close(cfd);
    close(lfd);
    return 0;
}




