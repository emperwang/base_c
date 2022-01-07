#include <stdio.h>

int main(){
	
	int i = 0, sum = 0;

	for( ; i <= 99; i++){
		sum = sum + i * (i+1);
	}

	printf("The sum is :%d\n", sum);

	return 0;
}
