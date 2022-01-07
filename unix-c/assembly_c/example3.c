#include <stdio.h>

int main()
{
    int in_a = 0x12345678, in_b = 0;
    asm volatile(
        "movl %1, %0;"
        : "=m"(in_b)
        : "a"(in_a));

    printf("in_b is: 0x%x\n", in_b);
    asm volatile(
        "movb %b1, %0;"
        : "=m"(in_b)
        : "a"(in_a));
    printf("in_b is: 0x%x\n", in_b);

    asm volatile(
        "movb %h1, %0;"
        : "=m"(in_b)
        : "a"(in_a));

    printf("in_b is: 0x%x\n", in_b);

    return 0;
}
