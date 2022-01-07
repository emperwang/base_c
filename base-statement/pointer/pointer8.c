#include<stdio.h>
void copy_str(char from[],char to[]){
	int i=0;
	while(from[i] != '\0'){
		to[i] = from[i];
		i++;
	}
	to[i]='\0';
}

int main(){
	char a[]="I am a teacher";
	char b[]="You are a teacher";
	printf("string a is %s,string b is :%s\n",a,b);
	copy_str(a,b);
	printf("after copy:string a is %s,string b is :%s\n",a,b);	
	return 0;
}