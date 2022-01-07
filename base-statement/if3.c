#include<stdio.h>
int main(){
	
	float score;
	
	char grade;
	
	printf("please input your score : ");
	
	scanf("%f",&score);
	if (score <= 60){
		grade = 'E';
	}else if(score <= 69){
		grade = 'D';
	}else if (score <= 79){
		grade ='C';
	}else if (score <= 89){
		grade = 'B';
	}else {
		grade = 'A';
	}
	
	printf("your grade is %c",grade);
	
	return 0;
}
