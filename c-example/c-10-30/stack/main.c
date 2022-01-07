#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
	sqstack *sk;
	sk = sqstack_create();
	if (sk == NULL){
		return NULL;
	}

	int i;
	for (i = 0; i< 20; i++){
		sqstack_push(sk,i);
	}
	sqstack_display(sk);

	sqstack_pop(sk,&i);
	printf("pop :%d\n", i);

	sqstack_display(sk);

	return 0;
}
