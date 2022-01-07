#include <stdio.h>

/*
 *打印各种指针额长度
 * */
int main(){
	printf("int* = %d\n",sizeof(int*));
	printf("char* = %d\n",sizeof(char*));
	printf("float* =%d\n",sizeof(float*));
	printf("long*  =%d\n",sizeof(long*));
	printf("double* = %d\n",sizeof(double*));
	printf("void* = %d\n",sizeof(void*));

	return 0;
}
