#include <stdio.h>
#include "sqlist.h"

int main(){

	datatype arr1[] = {1,3,5,7};
	datatype arr2[] = {2,4,6,8};
	sqlist *L1,*L2;
	int i=0,pos = 0;

	L1 = sqlist_create();
	for(i=0;i<sizeof(arr1)/sizeof(*arr1);i++){
		sqlist_insert(L1,pos,arr1[i]);
	}

	L2=sqlist_create();
	for(i=0;i<sizeof(arr2)/sizeof(*arr2);i++){
		sqlist_insert(L2,pos,arr2[i]);
	}
	
	sqlist_display(L1);
	sqlist_display(L2);

	sqlist_union(L1,L2);

	sqlist_display(L1);

	return 0;
}
