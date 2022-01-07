#include <stdio.h>

int main(){
	
	int a[3]={1,2,3};
	printf("%d\n",0[a]); // 0[a] = *(0+a) = *(a+0)

	return 0;
}
