#include <stdio.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>

/**
 * 查找某个 name对应的passwd结构信息
 */
struct passwd * getpwname(const char *name){
	struct passwd *ptr;

	setpwent();
	while((ptr = getpwent()) != NULL){
		if(strcmp(name, ptr->pw_name) == 0)
			break;
	}

	endpwent();
	return (ptr);

}
