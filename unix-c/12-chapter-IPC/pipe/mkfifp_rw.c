#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void usage(char*);

int checkfd(int fd)
{
    if(fd < 0)
    {
        perror("open file failed.\n");
        return -1;
    }
    return 0;
}

int main(int argc, char*argv[])
{
    if(argc < 2)
    {
        char* name = argv[0];
        usage(name);
        exit(1);
    }
    char* filename = argv[1];
    printf("pipe file name :%s.\n", filename);
    // check file exist
    if(access(filename,F_OK) == 0)
    {
        printf("pipe file exists");
    }else
    {
        // create file if no exist
    int ret = mkfifo(filename, 755);
        if(ret < 0)
        {
            printf("create pipe failed.\n");
            exit(2);
        }
    }
    pid_t pid;
    // create process
    pid = fork();
    if(pid < 0)
    {
        perror("fork process failed.\n");
        exit(3);
    }
    // child read
    if(pid == 0)
    {
        // open file for read write
        int cfd = open(filename,O_RDWR);
        if(checkfd(cfd) < 0)
        {
            exit(4);
        }
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        for(;;)
        {
            // read from pipe
            int n = read(cfd, buf, sizeof(buf));
            printf("read from parent: %s\n", buf);
            // read from stdin then write the content to pipe
            char *res = fgets(buf, sizeof(buf), stdin);
            printf("child read from stdin: %s", buf);
            if(res)
            {
                write(cfd, res, sizeof res);
            }
        }
    }

    // parent write
    // open pipe for read write
    int pfd = open(filename,O_RDWR);
    if(checkfd(pfd) < 0)
    {
        exit(4);
    }
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    // read from stdin then write the content to pipe
    for(;;)
    {
        // read from stdin then write the content to pipe
        char * reads = fgets(buf, sizeof(buf), stdin);
        printf("parent read from stdin: %s, return value: %s.\n", buf, reads);
        if(reads)
        {
            write(pfd, reads, sizeof(reads));
        }
        // read from child
        int num = read(pfd, buf, sizeof(buf));
        if(num < 0)
        {
            perror("read from child failed.\n");
        }
        else
        {
            printf("read from child: %s.\n", buf);
        }
    }
    return 0;
}


void usage(char* name)
{
    printf("usage: %s filename.\n",name);
}

