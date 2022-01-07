#include<stdio.h>
int main(){
	struct str{
		int num;
		char *name;
		char sex;
		float score;
	}boy1,boy2;
	boy1.num=102;
	boy1.name="zhangsan";
	printf("please input sex and score\n");
	scanf("%c %f",&boy1.sex,&boy1.score);
	
	boy2=boy1;
	printf("num=%d,name=%s,sex=%c,score=%f\n",boy2.num,boy2.name,boy2.sex,boy2.score);
	return 0;
}