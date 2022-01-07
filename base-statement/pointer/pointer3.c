#include<stdio.h>
int main(){
	
	int a=100;
	int b=200;
	// ÷∏’Î∂®“Â 
	int *pointer=&a;
	int *pointer_2=&b;
	
	printf("pointer_1=%d",*pointer);
	printf("pointer_2=%d\n",*pointer_2);
	
	return 0;
}