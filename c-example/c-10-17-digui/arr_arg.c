#include <stdio.h>

void print_value(int a[], int length);

int main(int argc, char* argv[]){

	int num[5] = {1,2,3,4,5};
	
	print_value(num,5);

	return 0;
}

/*
 * 数组作为函数的参数时，是传递的数组的首地址，是一个地址
 * */
void print_value(int a[], int length){
	
	int i= 0;
	for (i=0; i<length; i++){
		printf("%d\t", a[i]);
	}
	putchar('\n');
}

