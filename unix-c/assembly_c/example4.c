#include <stdio.h>

int main()
{
    int ina = 18, inb = 3, out = 0;
    asm volatile(
        "divb %[divisor];"
        "movb %%al,%[result];"
        : [ result ] "=m"(out)
        : "a"(ina), [ divisor ] "m"(inb));

    printf("result is: %d\n", out);

    return 0;
}
