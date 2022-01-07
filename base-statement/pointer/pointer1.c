#include<stdio.h>
int main(){
	int a=100,b=200;
	int *pointer_1,*pointer_2;
	// ÷∏’Î∂®“Â 
	pointer_1=&a;
	pointer_2=&b;
	
	printf("pointer_1 = %d\n",*pointer_1);
	printf("pointer_2 = %d\n",*pointer_2);
	
	return 0;
}