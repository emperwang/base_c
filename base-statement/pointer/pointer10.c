#include<stdio.h>
int main(){
	// 指向指针的指针
	char *name[]={"Follow me","basic","Great wall","computer"};
	char **p;
	int i;
	for(i=0;i<4;i++){
		p=name+i;
		printf("string is: %s\n",*p);
	}
	return 0;
}