#include <stdio.h>

int sum(int num1, int num2);

int main(int argc, char*argv[]){
	int num1=0,num2=0,add=0;
	printf("please enter two digit:\n");

	scanf("%d%d",&num1,&num2);
	add = sum(num1,num2);
	printf("the add is :%d\n", add);

	return 0;

}

int sum(int num1,int num2){
	int sum = 0;
	int i = num1;
	
	while(i >= num2){
		sum += i--;
	}

	return sum;

}
