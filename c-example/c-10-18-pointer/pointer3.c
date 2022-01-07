#include <stdio.h>

int main(){
	
	int num = 10;
	char chsign = 'a';
	int *q = &num;

	printf("q addr = %p\n",q);
	printf("q val  = %d\n",*q);
	printf("num addr = %p\n",&num);
	void *p = q;
	printf("p adrr %p\n",p);
	p = &chsign;
	printf("p addr = %p\n",p);
	printf("chs addr = %p\n",&chsign);
	
	return 0;
}
