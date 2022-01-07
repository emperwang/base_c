#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pwd.h>
#include <errno.h>
#include <string.h>

static void my_alarm(int signo){
	struct passwd *rootptr;
	printf("In signal handler");
	
	if((rootptr = getpwnam("root")) == NULL){
		perror("getpwdnam(root) error");
	}

	alarm(1);
}

int main(){
	
	struct passwd *ptr;

	signal(SIGALRM, my_alarm);
	alarm(1);

	for(;;){
		if((ptr = getpwnam("hive")) == NULL){
			perror("getpwnam(hive) error");
		}

		if(strcmp(ptr->pw_name, "hive") != 0){
			printf("return value corruped! pwd_name=%s\n", ptr->pw_name);		
		}
	}

	exit(1);
}
