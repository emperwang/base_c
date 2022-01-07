#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	
	srand(getpid());

	while(1){
		printf("%d\n",rand()%20+80);
		fflush(NULL);
		sleep(1);
	}

	return 0;
}
