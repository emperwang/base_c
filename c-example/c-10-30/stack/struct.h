#ifndef _STRUCT_H_ 
#define _STRUCT_H_

#define MAXSIZE 32

typedef int type;

typedef struct {
	type data[MAXSIZE];
	int top;
}sqstack;

#endif
