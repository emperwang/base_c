#include <stdio.h>
#include <string.h>

void sort(char * arr[], int);

int main(){

	int i = 0;
	
	char* arr[8] = {
		"bmy country",
		"dhere are",
		"end is",
		"fow are",
		"gt none",
		"a peeace",
		"hake and fruit",
		"cason"
	};
	sort(arr,8);

	for(i=0;i<8;i++){
		printf("%s\n", *(arr+i));
	}
	
	return 0;

}
// 对字符串进行排序，用到 指针数组，冒泡排序，strcmp
void sort(char * arr[], int n){
	int i,j;
	char* p =NULL;
	for (i=0;i<n-1;i++){
		for (j=0;j<n-1;j++){
			if (strcmp(*(arr+j),*(arr+j+1)) > 0){
				p = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = p;
			}
		}
	}
}




