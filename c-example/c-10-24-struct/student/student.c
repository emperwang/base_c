#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "struct.h"

int Init(STU* p){
	p->id = 0;
	p->name = malloc(sizeof(char));
	*(p->name) = '\0';
	p->math = 0;

	return 0;
}

int Set(STU *p){
	char buf[128];
	printf("Please enter(usage: id  name  math):\n");
	scanf("%d%s%f",&p->id,&buf,&p->math);
	p->name = malloc(strlen(buf)+1);
	strcpy(p->name, buf);
	return 0;
}

void Show(STU *p){
	printf("%d %s %f\n",p->id, p->name, p->math);
}

void Changename(STU *p, const char *newname){
	free(p->name);
	p->name = malloc(strlen(newname)+1);
	strcpy(p->name,newname);
}

void Destory(STU *p){
	free(p->name);
}
