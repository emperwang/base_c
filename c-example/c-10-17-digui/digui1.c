#include <stdio.h>

int multi(int);

int main(){
	
	int i;
	scanf("%d", &i);
	printf("value = %d\n",multi(i));

	return 0;

}

int multi(int n){
	if ( n == 1){
		return 1;
	}
	return n * multi(n-1);
}
