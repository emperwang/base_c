#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

sequeue *sequeue_create(){
	sequeue *sq;
	sq = malloc(sizeof(*sq));
	if (sq == NULL)
		return NULL;
	sq->front = sq->rear = 0;

	return sq;
}

int sequeue_enqueue(sequeue *L, type x){
	if((L->rear+1) % SIZE == L->front){
		return -1;			// 满了
	}
	L->rear = (L->rear + 1)%SIZE;
	L->data[L->rear] = x;

	return 0;
}

int sequeue_dequeue(sequeue *L, type *x){
	if(L->front == L->rear){// empty
		return -1;
	}

	L->front = (L->front+1)%SIZE;
	*x = L->data[L->front];

	return 0;
}

int sequeue_is_empty(sequeue *L){
	return (L->front == L->rear);
}

void sequeue_display(sequeue *L){
	int i = (L->front+1) % SIZE;
	if(sequeue_is_empty(L)){
		return;
	}
	while(i != L->rear){
		printf("%d ", L->data[i]);
		i = (i+1)%SIZE;
	}
	printf("%d \n", L->data[i]);
}

void sequeue_clear(sequeue *L){
	L->front = L->rear;
}
