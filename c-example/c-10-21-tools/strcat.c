#include <stdio.h>

char* strcat(char*, const char*);

int main(){

	char arr1[50] = "I you";
	char arr2[ ] = "forever";

	printf("%s\n", strcat(arr1,arr2));

	return 0;
}


char* strcat(char* dest, const char* src){
	char c;
	int i=0,j=0;
	while(*(dest+ i++) != '\0');

	i--;

	while((c = *(src+j++)) != '\0'){
		*(dest+i++) = c;
	}

	*(dest+i) = '\0';
	return dest;
}
