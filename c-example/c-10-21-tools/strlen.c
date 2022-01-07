#include <stdio.h>

int strlen(char*);

int main(){
	
	char arr[] = "banana";
	printf("the arr[] lenth is :%d\n", strlen(arr));

	return 0;
}

int strlen(char *s){
	int i=0;
	while(s[i++] != '\0');

	return i;
}

