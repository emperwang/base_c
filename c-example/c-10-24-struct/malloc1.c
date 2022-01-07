#include <stdio.h>
#include <malloc.h>

int fun(int **p, int size){
	*p = (int *)malloc(size);
	if(*p == NULL){
		printf("ret = %d\n",-1);
		return -1;
	}else{
		printf("ret = %d\n",0);
		return 0;
	}
}

int main(){
	
	int *p = NULL;
	fun(&p,100);
	free(p);

	return 0;
}
