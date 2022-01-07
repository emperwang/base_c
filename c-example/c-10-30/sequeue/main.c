#include <stdio.h>
#include <stdlib.h>
#include "sequeue.h"

int main(){
	
	sequeue *sq;
	sq = sequeue_create();
	if(sq == NULL){
		printf("create error\n");
		return NULL;
	}

	int i = 0;
	for (i = 0;i<10; i++){
		sequeue_enqueue(sq,i);
	}

	sequeue_display(sq);
	
	sequeue_dequeue(sq,&i);
	printf("dequeue %d\n",i);

	sequeue_display(sq);

	return 0;
}
