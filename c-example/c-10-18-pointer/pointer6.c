#include <stdio.h>

int main(){
	
	int i = 0;;
	int arr[5] = {1,2,3,4,5};

	int *p = NULL;  // *p = &arr
	p = arr;

	for (i=0; i < 5; i++){
		printf("*(p+%d)=%d\n",i, *(p+i));
	}
	for (i=0; i < 5; i++){
		printf("*(arr+%d)=%d\n",i, *(arr+i));
	}
	for (i=0; i < 5; i++){
		printf("arr[%d]=%d\n",i, arr[i]);
	}
	for (i=0; i < 5; i++){
		printf("p[%d=%d\n",i, p[i]);
	}

	return 0;
}
