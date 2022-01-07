#include <stdio.h>

int main(int argc, char* argv[]){
	
	char name, sex;
	char name1[10],sex1[10];
	printf("please enter your name, sex:\n");
	scanf("%c,%c", &name, &sex);
	printf("name is:%c\n",name);
	printf("sex is :%c\n", sex);
	
	printf("please enter your name1, sex1:\n");
	scanf("%s%s", name1, sex1);

	printf("name1 is:%s\n",name1);
	printf("sex is :%s\n", sex1);

	return 0;
}
