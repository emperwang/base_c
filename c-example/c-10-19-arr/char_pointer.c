#include <stdio.h>
#include <string.h>

int main(){
	char str[] = "hello";
	char str1[] = "world";
	char *p = "hello";// "hello" 是常量字符串，存储在内存的date区

	strcpy(p,str1);// 意图修改hello常量对应的data区内容是不允许的，程序报段错误
	printf("%s\n",p);

	return 0;
}
