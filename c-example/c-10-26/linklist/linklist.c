#include <stdio.h>
#include <malloc.h>
#include "struct.h"

int Insert(struct node_st **L, struct score* data){
	struct node_st *new;
	new = (struct node_st *)malloc(sizeof(*new));

	if(new == NULL){
		return -1;
	}

	new->data = *data;
	new->next = *L;
	*L= new;
	return 0;
}

struct score *Find(struct node_st *L, int id){
	struct node_st *cur;

	for(cur = L; cur != NULL; cur = cur->next){
		if(cur->data.id == id){
			return &(cur->data);
		}
	}
}

void Show(struct node_st *L){
	struct node_st *cur;

	for(cur = L;cur != NULL; cur=cur->next){
		printf("%d %s %d\n", cur->data.id, cur->data.name, cur->data.math);
	}
}

