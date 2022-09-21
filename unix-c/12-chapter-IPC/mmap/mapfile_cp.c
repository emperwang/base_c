#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <error.h>
#include <sys/mman.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
    // open file, create it if not exist
    int fd = open("file2", O_RDWR|O_CREAT,S_IRWXU|S_IRGRP|S_IROTH);
    long page_size = sysconf(_SC_PAGESIZE);
    // extend file size
    lseek(fd, page_size, SEEK_SET);
    write(fd,"",1);
    // mmap file
    void* ptr = mmap(NULL,page_size, PROT_READ|PROT_WRITE,MAP_SHARED, fd, 0);
    if(ptr)
    {
        printf("mmap success.\n");
    }else
    {
        perror("mmap failed.\n");
        exit(1);
    }
    close(fd);
    // create process
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("fork failed.\n");
        exit(3);
    }
    // child read
    if(pid == 0)
    {
        int idx = 0;
        while(idx < 10)
        {
            printf("child read from mmap: %s. \n", (char*)ptr);
            sleep(2);
            idx++;
        }
        // read from mmap
        exit(0);
    }
    // parent write
    // write content to mmap
    char* buf = "1234567890";
    memcpy((char*)ptr, buf, sizeof(buf));
    int ret = 0;
    if((ret = waitpid(pid, NULL,NULL)) < 0 )
    {
        perror("waitpid error.\n");
    }
    return 0;
}
