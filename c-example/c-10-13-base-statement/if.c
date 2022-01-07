#include <stdio.h>

int main(){
	
	int num1 = 0;
	int num2 = 0;

	printf("please enter two number:\n");
	scanf("%d%d", &num1,&num2);

	if (num1 > num2 ){
		printf("the max number is :%d\n", num1);
	}else {
		printf("the max number is :%d\n",num2);
	}
	return 0;
}
