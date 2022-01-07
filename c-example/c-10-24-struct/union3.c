#include <stdio.h>
// 利用union和struct的嵌套实现0x11223344的高位和低位相加

union unsign_int{

	struct num_stru{
		unsigned short low;
		unsigned short high;
	}n;

	union num_un{
		unsigned int u;
	}m;
};

int main(){
	union unsign_int x;
	x.m.u=0x11223344;
	printf("%x+%x=%x\n",x.n.low,x.n.high,x.n.low+x.n.high);

	return 0;
}

