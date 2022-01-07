#include<stdio.h>
int max(int a,int b){
	int z;
	if(a>=b){
		z=a;
	}else{
		z=b;
	}
	return z;
}

int main(){
	// 函数指针 
	int (*p)();
	p=max;	// 函数指针赋值
	int a=100,b=200,c;
	c = (*p)(a,b);  // 调用函数 
	printf("max num is:%d\n",c); 
	
	return 0;
}