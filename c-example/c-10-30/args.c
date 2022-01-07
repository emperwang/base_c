#include <stdio.h>

int add(int a,...)
{
	int sum = 0;
	int *p = &a;
	while(*p != 0)
		sum += *p++;
	return sum;
}

int main()
{
	int sum; 
	sum = add(1,2,3,14,5,6,10,10,10,10,89,0);
	printf("%d\n",sum);
}

