#include<stdio.h>
int max(int a ,int b){
	int z;
	if(a>=b){
		z=a;
	}else{
		z=b;
	}
	return z;
}

int min(int a,int b){
	int z;
	if(z>=b){
		z=b;
	}else{
		z=a;
	}
	return z;
}

int add(int a,int b){
	return a+b;
}
/**
�������Ϊ  ����ָ�� 
*/
int process(int a,int b,int (*fun)(int,int)){
	int z = (*fun)(a,b);
	return z;
}

int main(){
	int a=10,b=20,c;
	// ���ò���Ϊ ����ָ��ĺ���; ͨ�����ݲ�ͬ�ĺ���,ʵ�ֲ�ͬ�Ĺ��� 
	c=process(a,b,min);
	printf("min num is :%d\n",c);
	c=process(a,b,add);
	printf("sum is %d\n",c);
	return 0;
}