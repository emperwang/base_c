#include <stdlib.h>
#include "list.h"

list *listCreate(){
	struct list *list;
	if ((list = malloc(sizeof(*list))) == null){
		printf("malloc error");
		return null;
	}
	list->head = list->tail= null;
	list->len = 0;
	list->dup = null;
	list->free = null;
	list->match = null;
	
	return list;	
}

void printList(list *list){
	listNode *n = listFirst(list);
	if(list->len <= 0){
		printf("empty list\n");
		return;
	}
	int i;
	for( i = 0; i < list->len; i++){
		printf("%s \n", n->value);
		n = n->next;	
	}	
}
/*
* 从开始添加节点 
*/
list *listAddNodeHead(list *list, void *value){
	listNode *node;
	if((node = malloc(sizeof(*node))) == null){
		printf("head node malloc failed\n");
		return list;
	}
	node->value= value;
	if (list->len == 0){
		list->head = list->tail = node;
		node->prev = node->next = null; 
	}else{
		node->prev = null;
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->len++;
}
/*
*  从末尾开始添加节点 
*/
list *listAddNodeTail(list *list, void *value){
	listNode *node;
	if((node = malloc(sizeof(*node))) == null){
		printf("tail node malloc failed\n");
		return list;
	}
	node->value = value;
	if(list->len == 0){
		list->head = list->tail = node;
		node->prev = node->next = null;
	}else{
		node->prev = list->tail;
		node->next = null;
		list->tail->next = node;	
		list->tail = node;
	}
	list->len++;
}

