#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TOK_ADD 5

void do_line(char *);
void cmd_add(void);
int get_token(void);


int main(){
	char line[1024];

	while(fgets(line, 1024, stdin) != NULL){
		do_line(line);
	}
	exit(0);
}

char * tok_ptr;

void do_line(char *ptr){
	int cmd;

	tok_ptr = ptr;
	while((cmd = get_token()) > 0){
		switch(cmd){
			case TOK_ADD:
				cmd_add();
				break;
		}
	}
}


void cmd_add(){
	int token;
	token = get_token();

}

int get_token(){
	// fetch next token from line pointed to by tok_ptr;
}



