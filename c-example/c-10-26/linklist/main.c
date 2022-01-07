#include <stdio.h>

#include "linklist.h"

int main(){
	struct node_st *head = NULL;

	int i, id = 13;
	struct score tmp, *retp;
	for(i=0;i<8;i++){
		tmp.id = i;
		tmp.math = 100 - i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		Insert(&head, &tmp);
	}
	Show(head);

	printf("\n");

	retp = Find(head, id);

	if(retp == NULL){
		printf("can not find!\n");
	}else{
		printf("%d   %s   %d\n",retp->id, retp->name, retp->math);
	}

	return 0;
}
