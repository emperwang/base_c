#include <stdio.h>

int main(){
	enum members{
		one=1,
		two,
		three,
		four,
		five
	};

	enum members num1,num2,num3;

	for (num1 = one; num1 <= five; num1++){
		for ( num2=one; num2 <= num1; num2++){
			num3 = (enum members)num1*num2;
			printf("%d*%d=%d\t", num1,num2,num3);
		}
	}
	return 0;
}
