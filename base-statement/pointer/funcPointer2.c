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
	// ����ָ�� 
	int (*p)();
	p=max;	// ����ָ�븳ֵ
	int a=100,b=200,c;
	c = (*p)(a,b);  // ���ú��� 
	printf("max num is:%d\n",c); 
	
	return 0;
}