#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <unistd.h>

/**
 * 从关闭写端 进行读取操作
 */
int main()
{
    pid_t pid;

    int pfd[2] = {0};
    // create pipe
    int ret = pipe(pfd);
    if(ret < 0)
    {
        perror("create pipe failed.\n");
        exit(1);
    }
    // create process
    pid = fork();
    if(pid < 0)
    {
        perror("fork failed.\n");
        exit(2);
    }
    // child process
    if(pid == 0)
    {
        close(pfd[1]);
        printf("child start to read.\n");
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        int count = 0;
        while(count < 30)
        {
            // close write pipe,  read return 0
            int num = read(pfd[0], buf, sizeof(buf));
            printf("child read count: %d.\n", num);
            memset(buf, 0, sizeof(buf));
            sleep(1);
            count++;
        }
        // child exist
        exit(0);
    }
    // parent
    // close read and write
    printf("parent close pipe.\n");
    close(pfd[1]);
    close(pfd[0]);
    int status = 0;
    if((ret = waitpid(pid, &status, 0)) < 0)
    {
        perror("wait child failed.\n");
        exit(3);
    }

    return 0;
}
