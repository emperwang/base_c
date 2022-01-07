#include <stdio.h>

int main(int argc, char* argv[]){

	int i = 0;
	if (argc  <= 1){
		printf("usage: %s  param1  param2 ...\n", argv[0]);
		return 0;
	}
	for ( i = 1; i < argc; i++){
		printf("%s\n", argv[i]);	
	}
	return 0;
}
