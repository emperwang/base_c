#include <stdio.h>

int nn(int);

int main(){
	
	int i;
	printf("please input a num:\n");
	scanf("%d", &i);
	printf("1*1+2*2+3*3..%d*%d=%d\n",i,i,nn(i));

	return 0;
}


/*
 *实现 1*1+2*2+3*3+4*4  的规律
 * */
int nn(int n){
	if ( n ==1 )
		return 1;

	return n*n + nn(n-1);
}
