#include <stdio.h>

int main()
{
    int ina = 1, inb = 2;
    asm volatile(
        "addl %%ebx, %%eax;"
        : "+a"(ina)
        : "b"(inb));

    printf("ina is %d\n", ina);
    return 0;
}
