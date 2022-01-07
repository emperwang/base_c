#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

sqstack *sqstack_create(){
	
	sqstack *L;
	L = malloc(sizeof(*L));
	if(L== NULL){
		return NULL;
	}

	L->top = -1;

	return L;
}

int sqstack_push(sqstack *L, type x){
	if(L->top == MAXSIZE-1){
		return -1;
	}

	L->data[++L->top] = x;

	return 0;
}

int sqstack_pop(sqstack *L,type *x){
	if(L->top == -1){
		return -1;
	}
	*x = L->data[L->top--];
	return 0;
}

int sqstack_top(sqstack *L, type *x){
	if(L->top == -1){
		return -1;
	}
	*x = L->data[L->top];
	return 0;
}

int sqstack_is_empty(sqstack *L){
	return (L->top == -1);
}

void sqstack_display(sqstack *L){
	int i;
	if (L->top == -1){
		return;
	}
	for(i =0; i <= L->top; i++){
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
