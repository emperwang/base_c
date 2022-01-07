#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	
	if(argc != 3){
		perror("usage : a.out  <directory> <prefix>");
	}
	
	printf("%s \n", tempnam(argv[1][0] != ' ' ? argv[1] :NULL,
							argv[2][0] != ' ' ? argv[2]: NULL));

	exit(0);
}
