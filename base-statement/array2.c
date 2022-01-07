#include<stdio.h>
int main(){
	int i;
	int sum;
	float average,average2;
	int a[10] = {90,89,80,88,70,87,78,98,77,66};
	
	for(i=0;i<10;i++){
		sum=sum+a[i];
	}
	average=sum/10.0;
	average2=sum/10;
	
	printf("sum is %d \n",sum);
	printf("average is %.3f \n",average);
	printf("average2 is %.3f \n",average2);
}
