#include <stdio.h>

void printsushu(int n, int m);

int main(){
	int i=1, j=1000;
	printsushu(i,j);
	return 0;
}

void printsushu(int n, int m){
	printf("hello, sushu is here:\n");
	int x,y,z=0;
	for (x=n; x<=m;x++){
		
		for(y=2;y<=x/2; y++){
			if (x%y == 0){
				break;
			}
		}
		if(y > x/2){
			z++;
			if (z % 8==0){
				printf("\n");
			}
			printf("%d\t", x);
		}
	}
}
