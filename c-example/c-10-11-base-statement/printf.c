#include <stdio.h>

int main(int argc, char* argv[]){
	int i = 5, j= 6;
	printf("hello world!\n");	// string
	printf("the char is %c\n",'a');  // character
	printf("the sixtenth num is :%x\n",88);  // 十六进制
	printf("the eigth is :%o\n",88);		// 八进制
	printf("the string is :%s\n", "welcome to uplooking");	// 字符串
	printf("the float is :%f\n", 3.1415926f);	// 单精度
	printf("the double is :%lf\n", 2.1415926); // 双精度
	printf("the double .3f is :%.3f\n", 3.1415); //  改变精度为小数点后保留三位  %.3f
	printf("the double .8f is :%.8lf\n",3.1415926535);// 改变精度为小数点后8位
	printf("the address is :%p\n", &i);	// 以16进制的形式输出一个变量的地址
	printf("the address is :%x\n", &j);	// 以16进制的形式输出一个变量的地址

	return 0;
}
