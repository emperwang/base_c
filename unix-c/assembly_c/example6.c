#include <stdio.h>

int main()
{
    int ret_cnt = 0, test = 0;
    char *fmt = "hello world\n";
    // 此pushl 有错？报错如下： invalid instruction suffix for `push'
    asm volatile(
        "pushl %1;"
        "call printf;"
        "addl $4, %%esp;"
        "movl $6, %2;"
        : "=a"(ret_cnt)
        : "m"(fmt), "r"(test));

    printf("output %d nums char\n", ret_cnt);
    printf("test is: %d\n", test);
    return 0;
}
