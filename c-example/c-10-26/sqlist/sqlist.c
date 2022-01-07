#include <stdio.h>
#include <malloc.h>
#include "struct.h"

sqlist *sqlist_create(){
	
	 sqlist *L;
	 L = malloc(sizeof(*L));
	 if(L == NULL){
		return NULL;
	 }
	 L->last = -1;

	 return L;
}

int sqlist_insert(sqlist *L, int i, datatype x){
	int j= L->last;

	if (L->last == SIZE - 1){
		return -1;
	}
	if( i < 0 || i > L->last+1){
		return -2;
	}

	while( i <= j){
		L->data[j+1] = L->data[j];
		j--;
	}
	L->data[i] = x;
	L->last++;
	return 0;
}

void sqlist_display(sqlist *L){
	int i;
	if(L->data == -1){
		return;
	}

	for(i=0;i <= L->last; i++){
		printf("%d  ",L->data[i]);
	}
	printf("\n");
}

void sqlist_create2(sqlist **L){
	*L = malloc(sizeof(*L));
	if(*L == NULL){
		return;
	}
	(*L)->last = -1;
}

int sqlist_is_empty(sqlist *L){
	return (L->last == -1);
}

void sqlist_set_empty(sqlist *L){
	L->last = -1;
}

int sqlist_delete(sqlist *L, int i){
		int j;
		if (i<0 || i > L->last)
			return -1;
		for(j = i+1; j <= L->last; j++){
			L->data[j-1] = L->data[j];
		}
		L->last--;
		return 0;
}

int sqlist_find(sqlist *L, datatype x){
	int i= 0;

	for(i=0; i<= L->last; i++){
		if(L->data[i] == x)
			return i;
	}
	return -1;
}

int sqlist_get(sqlist *L, int i, datatype *x){
	int ret;

	if( i<0 || i>L->last){
		return -2;
	}
	*x = L->data[i];
	return sqlist_delete(L,i);
}

void sqlist_destroy(sqlist *L){
	free(L);
	L= NULL;
}

void sqlist_union(sqlist *L1, sqlist *L2){
	int i = 0;
	while( i <= L2->last && L1->last < SIZE-1){
		if (sqlist_find(L1,L2->data[i]) == -1){
			sqlist_insert(L1,L1->last+1, L2->data[i]);
			i++;
		}
	}
}

