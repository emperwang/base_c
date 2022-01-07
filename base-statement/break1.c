#include<stdio.h>
int main(){
	char a,c;
	printf("input a string :\n");
	c=getchar();
	while((a=getchar()) != '\n'){
		if(a==c){
			printf("There is the same character %c\n",a);
			break;
		}
		c=a;
	}
	
	return 0;
}
