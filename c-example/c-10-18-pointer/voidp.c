#include <stdio.h>

int main(){
	int num = 304;
	char chsign = 'm';

	void *q = &chsign;

	printf("get *q val: %c\n",*(char*)q);

	return 0;
}
