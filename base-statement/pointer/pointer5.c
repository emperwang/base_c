#include<stdio.h>
int main(){
	int a[10];
	int i;
	for (i=0;i<10;i++){
		printf("please input num :");
		scanf("%d",&a[i]);	
	}
	
	printf("\n");
	for(i=0;i<10;i++){ // 通过指定来获取数组元素 
		printf("%d \t",*(a+i));
	}
	
	return 0;
}