#include <stdio.h>

int main(){
	int num1 = 10;
	int num2 = 20;

	int sum = num1 + num2;

	char s[20] = {0,10};

	sprintf(s, "%d + %d = %d", num1,num2,sum);
	printf("%s\n", s);

	return 0;
}
