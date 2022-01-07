#include<stdio.h>

int main(){
	int a[10];
	int *p,i;
	
	for(i=0;i<10;i++){
		printf("please input a num :");
		scanf("%d",&a[i]);
	}
	printf("\n");
	// 使用指针遍历数组
	// p=a 指向数组的指针 
	for(p=a;p<a+10;p++){
		printf("%d \t",*p);
	}
	
	return 0;
}