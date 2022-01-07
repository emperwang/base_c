#include <stdio.h>

int main(){
	
	int num = 0, max = 0;

	while (1){
		scanf("%d", &num);

		if (num == -1){
			break;
		}else if(num > max)
			max = num;
	}

	printf("the max value is :%d\n", max);

	return 0;
}
