#include <stdio.h>

union{

	struct {
		unsigned short low;
		unsigned short high;
	}x;
	unsigned int y;;
}num;

int main(){
	num.y=0x11223344;

	printf("low=%x, high=%x\n",num.x.low, num.x.high);

	printf("y==%x\n",num.y);

	return 0;
}
