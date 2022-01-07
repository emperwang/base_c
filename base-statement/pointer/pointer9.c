#include<stdio.h>
void copy_str(char *from,char *to){
	for(;*(from) != '\0';from++,to++){
		*(to) = *(from);	
	}
	*(to++)='\0';
}

int main(){
	char a[]="I am teacher";
	char b[]="You are teacher";
	char *p1,*p2;
	p1=a;
	p2=b;
	printf("string a is %s,stirng b is:%s\n",p1,p2);
	printf("\n");
	copy_str(p1,p2);
	printf("after copy,string a is %s,String b is :%s\n",p1,p2);
	return 0;
}