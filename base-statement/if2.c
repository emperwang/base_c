#include<stdio.h>

int main(){
	int a,b;
	
	printf("please input your compare num :");
	scanf("%d%d",&a,&b);
	
	printf("a is %d, b is %d \n",a,b);
	
	if(a > b){
		printf(" a is bigger than b\n");
	}else if(a < b){
		printf("a is littler than b\n");
	}else{
		printf("a is equals b\n");
	}
	
	
	return 0;
}
