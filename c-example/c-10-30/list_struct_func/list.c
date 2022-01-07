#include <stdio.h>
#include <string.h>

#include "struct.h"

int llist_insert(LLIST *, const void *data, int mode);
void llist_delete(LLIST *, const void *key, llist_cmp *cmp);
void *llist_find(LLIST *, const void *key, llist_cmp *cmp);
int llist_fetch(LLIST *, const void *key, llist_cmp *cmp, void *);
void llist_travel(LLIST *, llist_op *op);

LLIST *llist_create(int size){
	LLIST *handle;
	handle = malloc(sizeof(*handle));
	if(handle == NULL){
		return NULL;
	}
	handle->size = size;
	handle->head.prev = handle->head.next = &handle->head;

	handle->insert=llist_insert;
	handle->delete=llist_delete;
	handle->find=llist_find;
	handle->fetch=llist_fetch;
	handle->travel=llist_travel;

	return handle;
}


int llist_insert(LLIST *ptr, const void *data, int mode){
	struct llist_node_st *newnode;
	newnode = malloc(sizeof(*newnode)+ptr->size);
	if(newnode == NULL){
		return NULL;
	}
	memcpy(newnode->data, data, ptr->size);
	if(mode == FORWARD){
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
	}else if(mode == BACKWARD){
		newnode->prev = &ptr->head.prev;
		newnode->next = &ptr->head;
	}else{
		printf("mode error\n");
		return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	return 0;
}
static struct llist_node_st *find_(LLIST *ptr, const void *key, llist_cmp *cmp){
	struct llist_node_st *cur;
	for(cur = ptr->head.next; cur != &ptr->head; cur=cur->next){
		if(cmp(key, cur->data) == 0){
			break;
		}
	}
	return cur;
}

void *llist_find(LLIST *ptr, const void *key, llist_cmp *cmp){
	return (find_(ptr,key,cmp)->data);
}

void llist_delete(LLIST *ptr, const void *key, llist_cmp *cmp){
	struct llist_node_st *node;
	node = find_(ptr, key, cmp);
	if(node == &ptr->head){
		return ;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}
int llist_fetch(LLIST *ptr, const void *key, llist_cmp *cmp, void *data){

	struct llist_node_st *node;
	node = find_(ptr,key, cmp);
	if(node == &ptr->head){
		return -1;
	}
	memcpy(data, node->data, ptr->size);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	return 0;
}
void llist_travel(LLIST *ptr, llist_op *op){
	struct llist_node_st  *cur;

	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next){
		op(cur->data);
	}
}
