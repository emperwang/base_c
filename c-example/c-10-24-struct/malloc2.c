#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p;

	p = (int *)malloc(4);
	if (p == NULL){
		printf("malloc error\n");
		return -1;
	}

	*p = 1;
	printf("%d\n",*p);

	free(p);

	p = NULL;

	return 0;
}
