#include <stdio.h>
#include "list.h"

#define NAMESIZE 32

struct score{
	int id;
	char name[NAMESIZE];
	int math;
};

static void print_s(void *record){
	struct score *r = record;
	printf("%d  %s  %d\n", r->id,  r->name,  r->math);
}

static int id_cmp(const void *key,  const void *record){
	const int *k = key;
	const struct score *r = record;

	return (*k - r->id);
}

static int math_cmp(const void *key, const void *record){
	const int *k = key;
	const struct score *r = record;

	return (*k - r->math);
}

int main(){
	struct score tmp,*datap;
	int i,id, math;
	LLIST *handle;

	handle = llist_create(sizeof(struct score));
	if (handle == NULL){
		return -1;
	}
	for (i=0; i < 6; i++){
		tmp.id = i;
		tmp.math = 100 - i;
		snprintf(tmp.name,NAMESIZE, "stu%d",i);
		handle->insert(handle, &tmp,FORWARD);
	}
	handle->travel(handle, print_s);
	return 0;
}
