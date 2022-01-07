#include <stdio.h>

void out(int,int,int);

int main(){
	int a = 0, b = 0, c = 0;
	
	printf("please enter 3 digit:\n");

	scanf("%d%d%d", &a,&b,&c);
	out(a,b,c);

	return 0;
}

void out(int a,int b,int c){
	
	if (a > b){
		if ( b < c ){ // a > b >c
		printf("%d,%d,%d\n",c,b,a);
			
		}else if (c > b && c < a){ // a>c>b
		printf("%d,%d,%d\n",b,c,a);

		}else {	// c>a>b
		printf("%d,%d,%d\n",b,a,c);

		}
	}else if (c < a){ // b > a > c
		printf("%d,%d,%d\n",c,a,b);

	}else if (c > a && c < b){ // b > c > a
		printf("%d,%d,%d\n",a,c,b);

	}else {	// c > b > a
		printf("%d,%d,%d\n",a,b,c);
	}

}
