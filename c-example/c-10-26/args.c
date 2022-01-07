#include<stdio.h>

// 可变参数的使用,目前由问题
int add(int a,...){

	int sum = 0,i=0;
	int *p =&a;
	/*while(*p != 0){
		sum += *p++;
		printf("%d\n",sum);
	}*/

	va_list v1;	// va_list指针,用于va_start取可变参数,为char*
	va_start(v1,a);// 取得可变参数列表的第一个值
	printf("num:%d,v1:%d\n", a, *v1);
	for(i=0; i<(a-1);i++){
		sum = va_arg(v1,int);	// 把v1往后跳4个字节,指向下一个参数
		printf("in for result:%d, *v: %d\n",result,*v1);
	}
	va_end(v1);	// 结束标志

	return sum;
}

int main(){

	int sum;
	sum = add(4,1,2,3,0);

	printf("%d\n",sum);
	return 0;
}
