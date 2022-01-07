#include<stdio.h>

int main(){
	char a[]="I am a boy.",b[20];
	int i;
	// 相当于把字符数组进行了复制 
	for(i=0;*(a+i)!='\0';i++){
		*(b+i) = *(a+i);
	}
	// 填充最后一个字符为 \0 
	*(b+i) = '\0';
	// 打印 
	printf("string a is:%s\n",a);
	printf("string b is:%s\n",b);
	
	// 打印b数组的值 
	for(i=0;b[i]!='\0';i++){
		printf("%c \t",b[i]);
		printf("\n");
	}
	return 0;
}