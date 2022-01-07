#include <stdio.h>

struct student{

	int id;
	char name[32];
	float math;
};

void show(struct student *stu, int id, char *ch){
	id = 1;
	printf("%d\n", sizeof(stu));
	printf("%d,%s,%f\n", stu->id, stu->name, stu->math);
}

int main(){
	struct student str={123,"lisi",90};

	show(&str,str.id, str.name);

	return 0;
}
