#include<stdio.h>
struct stu{
	int num;
	char name[20];
	char sex;
	float score;
};

void ave(struct stu boy1,struct stu boy2){
	float ave=0;
	float s=0;
	s=boy1.score+boy2.score;
	ave=s/2;
	printf("total score is:%f\n",s);
	printf("ave score is :%f\n",ave);
}

int main(){
	struct stu boy1;
	struct stu boy2;
	printf("please input student's info:");
	scanf("%d %s %c %f",&boy1.num,&boy1.name,&boy1.sex,&boy1.score);
	printf("please input student's info:");
	scanf("%d %s %c %f",&boy2.num,&boy2.name,&boy2.sex,&boy2.score);
	
	ave(boy1,boy2);
	return 0;
}