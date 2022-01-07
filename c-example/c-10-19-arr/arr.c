#include <stdio.h>

int main(){
	
	int a[3] = {1,2,3};
	int i,*p=a;
	for (i=0;i<3;i++,p++){
		scanf("%d",p);
	}
	p=a;
	for(i=0;i<3;i++,p++){
		printf("%d  ",*p);
	}
	printf("\n");

	return 0;
}
