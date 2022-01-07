#include <stdio.h>
#include <unistd.h>
#include "student.h"

void menu(){
	
	printf("Please choice:\n");
	printf("1 set	2 show\n");
	printf("3 changename  4 quit\n");
}


int main(){
	
	STU stu;
	int i;
	char buf[128];

	Init(&stu);
	menu();
	while(scanf("%d", &i)){
		switch(i){
			case 1:
				Set(&stu);
				break;
			case 2:
				Show(&stu);
				break;
			case 3:
				printf("Enter a new name:\n");
				scanf("%s",buf);
				Changename(&stu,buf);
				break;
			case 4:
				Destory(&stu);
				return 1;
			default:
				Destory(&stu);
				return -1;
		}
		sleep(1);
		printf("\n\n");
		menu();
	}
	Destory(&stu);
	return 0;
}
