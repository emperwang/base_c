#include<stdio.h>
int main(){
	int sum,i;
	i=0;
	sum=0;
	while(i < 101){
		sum += i;
		i++;
	}
	
	printf("sum is %d\n",sum);
	return 0;
}
