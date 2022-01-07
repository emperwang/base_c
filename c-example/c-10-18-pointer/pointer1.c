#include <stdio.h>

int main(){
	int num = 28;
	int *p = &num;
	*p = 30;
	printf("p   addr = %p\n",p);
	printf("num adrr = %p\n", &num);
	printf("num=%d\n", num);
	printf("*p=%d\n",*p);

	return 0;
}
