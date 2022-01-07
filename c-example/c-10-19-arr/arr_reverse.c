#include <stdio.h>

// 对一个数组逆序
void arr_nixu(int *,int);

int main(){
	int i=0;
	int arr[9]={1,2,3,4,5,6,7,8,9};
	arr_nixu(arr,9);
	for (i=0;i<9;i++){
		printf("%d  ", *(arr+i));
	}
	printf("\n");

	return 0;
}

void arr_nixu(int *p,int n){
	int i,tmp;
	for (i = 0,n--;i<n;i++,n--){
		tmp = *(p+i);
		*(p+i) = *(p+n);
		*(p+n) = tmp;
	}
}
