#include<stdio.h>
int main(){
	int age;
	
	printf("please input your age:");
	
	scanf("%d",&age);
	
	if(age >= 8){
		printf("little student");
	} else if( age >= 15 && age <= 18){
		printf("middle high school");
	}else if (age > 18){
		printf("high school");
	}else{
		printf("not meeting reqirement");
	}
	
	return 0;
}
