#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main()
{

    int pipefd[2] = {0};
    // create pipe
    int ret = pipe(pipefd);
    if( ret < 0)
    {
        perror("pipe failed.");
        exit(1);
    }
    // fork process
    pid_t pid;
    pid = fork();
    if ( pid < 0)
    {
        perror("create child process failed.\n");
        exit(2);
    }
    // child
    if( pid == 0 )
    {
        // close write fd
        close(pipefd[1]);
        // read data from pipe
        char buf[1024];
        memset(buf, 0, sizeof(buf));

        int n = read(pipefd[0], buf, sizeof(buf));

        // print data
        printf("read count: %d, data: %s \n", n, buf);
        // exit child
        printf("child process existing");
        close(pipefd[0]);
        exit(0);
    }
    // parent
    close(pipefd[0]);
    // write data
    printf("parent write data to pipe.\n");
    char* hello = "hello world";
    printf("hello length: %d\n", strlen(hello));
    write(pipefd[1], hello, strlen(hello));
    // write(pipefd[1], "hello world", sizeof("hello world"));
    // release resource
    close(pipefd[1]);
    return 0;
}