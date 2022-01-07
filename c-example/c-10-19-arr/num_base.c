#include <stdio.h>

int main(){
	
	int num, base;
	int a[32];
	int i=0;

	printf("please enter(usage: num base(2,6,16)):\n");
	scanf("%d%d",  &num,&base);
	printf("num=%d--base=%d\n",num,base);
	if (!(base == 2 || base == 4 || base == 16)){
		return -1;
	}

	do {
		a[i] = num % base;
		i++;
		num /= base;
		printf("i=%d, a[%d]=%d\n",i,i,a[i]);
	}while(num != 0);
	
	for(i=i-1; i>=0;i--){
		if(a[i] >= 10){
			printf("%c",a[i]-10+'A');
		}else{
			printf("%d",a[i]);
		}
	}

	return 0;
}
