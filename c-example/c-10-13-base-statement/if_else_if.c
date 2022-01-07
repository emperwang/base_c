#include <stdio.h>

void pandu(char);

int main(void){
	
	char word;

	printf("please enter a word:\n");

	scanf("%c", &word);

	pandu(word);

	return 0;
}

void pandu(char s){
	
	if (s >= '0' && s <= '9'){
		printf("the word is digit\n");
	}else if (s >= 'a' && s <= 'z'){
		printf("thw word is xiaoxie_zimu\n");
	}else if(s >= 'A' && s <= 'Z'){
		printf("thw word is daxie_zimu\n");
	}else {
		printf("thw word is specifical charactern");
	}
}
