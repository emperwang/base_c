#include<stdio.h>
int main(){
	int n,i,j_sum,o_sum;
	printf("please input a num:");
	scanf("%d",&n);
	printf("count 1 to %d's  odd sum and even sum\n",n);
	
	j_sum=0;
	o_sum=0;
	
	for(i=1;i<=n;i++){
		if(i%2 == 0){
			o_sum += i;
		}else{
			j_sum += i;
		}
	}
	printf("from 1 to %d's odd sum is %d\n",n,j_sum);
	printf("from 1 to %d's even sum is %d\n",n,o_sum);
	return 0;
}
