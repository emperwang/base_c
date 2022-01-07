#include<stdio.h>
int main(){
	int n,i;
	i = 0;
	for(n=1;n<101;n++){
		if(n%3 == 0){   // 能被3整除则跳过 
			continue;
		}
		printf("num is %4d  ",n);
		i++;
		if(i%5==0){
			printf("\n");
		}
	}
	return 0;
}
