#ifndef _STRUCT_H_
#define _STRUCT_H_

#define SIZE 32
typedef int type;
typedef struct {
	type data[SIZE];
	int front;
	int rear;
}sequeue;

#endif
