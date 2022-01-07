#include <stdio.h>

int main(){
		
	int a[] = {1,2,3};
	printf("length=%d\n",sizeof(a)/sizeof(*a));
	
	int i;
	for (i=0;i<sizeof(a)/sizeof(*a); i++){
		printf("%d-->%p\n",*(a+i),a+i);
	}
	printf("\n");
	printf("%d\n",*(a+3));

	return 0;
}
