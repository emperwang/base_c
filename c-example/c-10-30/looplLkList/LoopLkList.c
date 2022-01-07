#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "struct.h"


LoopLkNode *createList(int n){

	LoopLkNode *L = NULL;
	LoopLkNode *p = NULL, *s = NULL;

	int i = 1;
	datatype e;
	while(i <= n){
		printf("Please enter %d number :\n",i);
		scanf("%d",&e);

		if(i == 1){
			if((L = malloc(sizeof(LoopLkNode))) == NULL){
				return NULL;
			}
			L->data = e;
			L->next = NULL;
			p = L;
		}else{
			if((s = malloc(sizeof(LoopLkNode))) == NULL){
				return NULL;
			}
			s->data = e;
			s->next = NULL;
			p->next = s;
			p = s;
		}
		i++;
	}
	p->next = L;		// 循环链表
	return L;
}

void showList(LoopLkNode *L){
	LoopLkNode *p;
	p = L;
	while(p->next != L){
		printf("%-4d",p->data);
		p = p->next;
	}
	printf("%-4d\n", p->data);
}



