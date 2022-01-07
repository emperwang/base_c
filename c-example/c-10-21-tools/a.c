#include <stdio.h>

int main(){
	
	int a[2][3] = {0};
	printf("a=%p, &a=%p,a+1=%p, &a+1=%p\n",
			a, &a, a+1,&a+1);

	return 0;
}
