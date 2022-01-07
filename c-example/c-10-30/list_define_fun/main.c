#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "list.h"

#define NAMESIZE 32

struct score{
	
	int id;
	char name[NAMESIZE];
	int math;
	struct list_head node;
};

static void print_s(void *record){
	
	struct score *r = record;
	printf("%d %s %d\n", r->id, r->name, r->math);
}

static void testoffset(){
	struct score *datap;

	datap = malloc(sizeof(*datap));
	if (datap == NULL){
		printf("malloc error\n");
		return 0;
	}
	printf("%p ", datap);	// 结构的地址
	printf("%p ", &datap->node);	// 结构node成员的地址
	printf("%p  ",offsetof(struct score,node));	// 成员地址到结构体地址的偏移 
}

int main(){
	int i;
	struct score *datap;
	struct list_head *cur;
	
	LIST_HEAD(head);
	for (i=0; i < 6; i++){
		datap = malloc(sizeof(*datap));
		if(datap == NULL){
			printf("malloc error\n");
			return -1;
		}
		datap->id = i;
		datap->math = 100-i;
		snprintf(datap->name,NAMESIZE, "std%d",i);
		list_add(&datap->node,&head);
	}
	__list_for_each(cur, &head){
		datap = list_entry(cur, struct score, node);
		print_s(datap);
	}

	printf("\n\n");

	__list_for_each(cur, &head){
		datap = list_entry(cur, struct score, node);
		if(datap->id == 30){
			break;
		}
	}
	
	if(cur == &head){
		printf("can not find\n");
	}else{
		print_s(datap);
	}

	return 0;
}



