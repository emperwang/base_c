#include <stdio.h>
#include "list.h"


int main(int argc,char *argv[]){
	struct list *list;	
	list = listCreate();
	printList(list);
	listAddNodeHead(list, "first");
	listAddNodeTail(list, "sec");
	listAddNodeTail(list, "third");
	printList(list);
	printf("%d\n", list->len);
}