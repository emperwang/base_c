#include <stdio.h>

/*
 *分别求出四行三列数组每一行的和，每一列的和以及所有元素的和
 * */
int main(){
	
	int i=0,j=0;
	int arr[5][4]  = {
		{1,2,3,0},
		{4,5,6,0},
		{7,8,8,0},
		{10,11,12,0},
	};
	for (i=0;i<4;i++){ // i遍历行，j遍历列
		for (j=0;j<3;j++){
			*(*(arr+i)+3) += *(*(arr+i)+j);
			*(*(arr+4)+j) += *(*(arr+i)+j);
			*(*(arr+4)+3) += *(*(arr+i)+j);
		}
	}
	for(i = 0; i< 4; i++){
		printf("the %d hang sum :%d\n",i,*(*(arr+i)+3));
	}

	for( i =0; i< 3; i++){
		printf("the %d lie sum:%d\n",i,*(*(arr+4)+i));
	}
	printf("the total sum:%d\n",*(*(arr+4)+3));
	return 0;
}
