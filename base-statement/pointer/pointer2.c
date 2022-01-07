#include<stdio.h>

void swap(int *p1,int *p2){
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int main(){
	int a=100,b=200;
	int *pointer_1,*pointer_2;
	// 指针定义 
	pointer_1=&a;
	pointer_2=&b;
	// 指针参数 
	swap(pointer_1,pointer_2);
	printf("pointer_1 =%d,pointer_2=%d\n",*pointer_1,*pointer_2);	
	
	return 0;
}