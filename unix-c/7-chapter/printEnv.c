#include <stdio.h>

extern char ** environ;

int main(){

	int idx = 0;

	for(idx=0; environ[idx] != NULL; idx++){
		printf("%s\n", environ[idx]);
	}

	return 0;
}
