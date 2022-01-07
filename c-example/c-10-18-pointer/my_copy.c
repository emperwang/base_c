#include <stdio.h>

void my_strcpy(char* dest,char* src);

int main(){
	
	char arr1[] = "khello";
	char arr2[] = "grils";
	my_strcpy(arr1,arr2);
	printf("%s\n", arr1);
	return 0;

}

void my_strcpy(char* dest,char* src){
	while ( *src != '\0' ){
		*dest++ = *src++;
	}	
}
