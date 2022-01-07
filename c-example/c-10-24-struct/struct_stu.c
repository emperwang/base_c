#include <stdio.h>

typedef struct student{
	
	int id;
	char name[32];
	float math;
}STU;

void set(STU* banana){
	puts("Enter the new student id:");
	scanf("%d", &banana->id);
	puts("Enter the new student name:");
	scanf("%s",&banana->name);
	puts("Enter math score:");
	scanf("%f", &banana->math);
}

void show(STU *stu){
	printf("%d  %s  %f\n",stu->id, stu->name, stu->math);
}

void changename(STU *stu){
	puts("Enter a new name:");
	scanf("%s", stu->name);
}

int main(){
	STU xx;
	set(&xx);
	show(&xx);
	changename(&xx);
	show(&xx);

	return 0;
}
