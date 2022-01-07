#include <stdio.h>

char* strcpy(char*, const char *);

int main(){
	char arr1[] = "I love you ";
	char arr2[] = "banana!";
	printf("arr1=%s, arr2=%s\n",arr1,arr2);

	strcpy(arr1,arr2);
	printf("after copy, arr1[] = %s\n", arr1);


	return 0;
}
char* strcpy(char*dest, const char *src){
	
	int i = 0;
	for(i=0; *(src+i) != '\0';i++){
		*(dest+i) = *(src+i);
	}
	*(dest+i) = '\0';

	return dest;
}
