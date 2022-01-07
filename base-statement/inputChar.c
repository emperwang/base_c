#include<stdio.h>
int main(){
	
	char c;
	
	printf("please input a character : ");
	c = getchar();
	
	if(c < 32){
		printf("This is a control character \n");
	}else if(c >= '0' && c <= '9'){
		printf("This is digit \n");
	}else if(c >= 'A' && c <= 'Z'){
		printf("This is a capital letter \n");
	}else if(c >= 'a' && c <= 'z'){
		printf("This is a small letter");
	}else{
		printf("This is an other character");
	}
	
	return 0;
}
