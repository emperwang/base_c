#include<stdio.h>
int main(){
	int i;
	int a[10] = {90,89,80,88,70,87,78,98,77,66};
	
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=9;i>=0;i--){
		printf("%d ",a[i]);
	}
	return 0;
}
