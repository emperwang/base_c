#include <stdio.h>
#include <stdlib.h>

int cmp(const void *data1, const void *data2){

	const int *d1 = data1;
	const int *d2 = data2;
	
	return (*d1-*d2)>0?-1:1;
}


int main(){

	int arr[] = {21,12,3,45,25,6,17,81,79};
	int i;

	qsort(arr,sizeof(arr)/sizeof(*arr), sizeof(*arr),cmp);

	for(i=0; i<sizeof(arr)/sizeof(*arr); i++){
		printf("%d\n",arr[i]);
	}

	printf("\n");

	return 0;

}
