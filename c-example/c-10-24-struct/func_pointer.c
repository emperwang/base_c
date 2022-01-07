#include <stdio.h>
#define N 2

int add(int a, int b){
	
	return a+b;
}

int munis(int a,int b){

	return a-b;
}

int main(){
		
	int i;
	int a=88,b=58,c;
	// 定义函数指针数组，数组中每个元素存储指向返回值位int，参数为两个int类型函数的地址
	int (*p[N])(int a,int b);
	
	p[0]=add;
	p[1]=munis;
	for (i = 0; i <N;i++){
		printf("%d\n", p[i](a,b));
	}

	return 0;
}
