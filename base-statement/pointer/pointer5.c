#include<stdio.h>
int main(){
	int a[10];
	int i;
	for (i=0;i<10;i++){
		printf("please input num :");
		scanf("%d",&a[i]);	
	}
	
	printf("\n");
	for(i=0;i<10;i++){ // ͨ��ָ������ȡ����Ԫ�� 
		printf("%d \t",*(a+i));
	}
	
	return 0;
}