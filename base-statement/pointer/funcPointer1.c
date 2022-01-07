#include<stdio.h>

int max(int a,int b){
	int z=0;
	if(a>=b){
		z=a;
	}else{
		z=b;
	}
	return z;
}

int main(){
	int a=100,b=200;
	int c;
	c=max(100,200);	
	printf("max num is %d\n",c);
	return 0;
}