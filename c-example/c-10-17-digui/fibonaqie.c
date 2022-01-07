#include <stdio.h>

int fi(int);

int main(){
	int n;
	printf("enter a number:\n");
	scanf("%d", &n);

	printf("the %d fi is :%d\n",n, fi(n));

	return 0;
}

/*
 * 实现 1 1 2 3 5 8 13... 第n项 的规律
 * */
int fi(int n){
	if ( n < 3)
		return 1;
	return fi(n-1)+fi(n-2);
}
