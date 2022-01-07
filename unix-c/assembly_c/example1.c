#include <stdio.h>

int in_a = 1;
int in_b = 2;
int out_sum = 0;

int main()
{
    /*
     求 in_a 和in_b 的和,并把结果放入到 out_sum中
    */
    /**
    * "=a"(out_sum)  表示输出结果放入到 out_sum中,=表示之只写,a表示把eax寄存器中 放入到 out_sum中
    * "a"(in_a)  表示把变量放入到寄存器  ax中
    * "b"(in_b)  表示把变量in_b 放入到寄存器 bx中
    */
    __asm__ volatile(
        "addl %%ebx,%%eax"
        : "=a"(out_sum)
        : "a"(in_a), "b"(in_b));

    printf("sum is %d\n", out_sum);
    return 0;
}