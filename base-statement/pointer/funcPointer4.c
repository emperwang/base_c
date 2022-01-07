#include<stdio.h>
float *search(float(*pointer)[4],int n);

int main(){
	float score[][4]={
		{60,70,80,90},	
		{61,71,81,91},
		{62,72,82,92}};
	float *p;
	int i,m;
	printf("Enter the number of student:");
	scanf("%d",&m);
	printf("The scores of No.%d are:\n",m);
	p=search(score,m);
	for(i=0;i<4;i++){
		printf("%5.2f\t",*(p+i));
	}
	return 0;
}
/**
返回值为指针类型的函数 
*/
float *search(float(*pointer)[4],int n){
	float *pt;
	pt = *(pointer+n);
	return pt;
}
