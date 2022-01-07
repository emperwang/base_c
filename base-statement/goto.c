#include<stdio.h>
int main(){
	int sum,i;
	sum = 0;
label: 
	if( i<= 100){
		sum += i;
		i++;
		goto label;
	}
	
	printf("sum = %d \n",sum);
	return 0;
}
