#include<stdio.h>

int main(){
	int a[10];
	int *p,i;
	
	for(i=0;i<10;i++){
		printf("please input a num :");
		scanf("%d",&a[i]);
	}
	printf("\n");
	// ʹ��ָ���������
	// p=a ָ�������ָ�� 
	for(p=a;p<a+10;p++){
		printf("%d \t",*p);
	}
	
	return 0;
}