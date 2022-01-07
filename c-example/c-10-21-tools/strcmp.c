#include <stdio.h>

// strcmp实现

int strcmp(const char * s1,const char *s2);

int main(){
	int i =0;
	char arr1[] = "zello";
	char arr2[] = "hello";

	i = strcmp(arr1,arr2);
	printf("arr1=%s, arr2=%s\n",arr1,arr2);
	if(i>0){
		printf("arr1 > arr2\n");
	}else if(i<0){
		printf("arr1 < arr2\n");

	}else {
		printf("arr1 == arr2\n");

	}
	return 0;
}
int strcmp(const char * s1,const char *s2){
	int i=0;
	while(*(s1+i) != '\0'){
	
		if(*(s2+i) != '\0'){
			if(*(s1+i) != *(s2+i)){
				return *(s1+i) - *(s2+i);
			}else{
				i++;
			}

		}else{
			return 1;
		}
	}
	if(*(s1+i) == '\0' && *(s2+i) == '\0'){
		return 0;
	}else {
		return -1;
	}

}

