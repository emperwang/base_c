#include <stdio.h>

int main(){
	
	char arr1[] = "welcome";
	char* p = "you";

	*arr1 = 'W';

	printf("%s\n", p);

	printf("%s\n", arr1);

	return 0;
}
