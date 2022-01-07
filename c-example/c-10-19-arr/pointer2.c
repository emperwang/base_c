#include <stdio.h>

// 对二级指针的理解
/**
 *
 *  int i = 1;
 *  int *p = &i;
 *  int **q = &p;
 *
 * 地址  0x8000			0x3000			0x2000
 * 值:	 0x3000 		0x2000			1
 *			q				p			i
 *
 */

int main(){
	int i = 100;
	int *p = NULL;
	int **q = NULL;

	p = &i;
	q = &p;

	printf("&i = %p\n",&i);
	printf("p = %p\n",p);
	printf("&p = %p\n",&p);
	printf("q = %p\n",q);
	printf("*q = %p\n",*q);
	
	printf("i = %d\n",i);
	printf("*p = %d\n",*p);
	printf("**q = %d\n",**q);

	return 0;
}
