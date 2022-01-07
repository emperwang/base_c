#ifndef _STRUCT_H_
#define _STRUCT_H_

#define NAMESIZE 32

struct score{
	int id;
	char name[NAMESIZE];
	int math;
};

struct node_st{
	struct score data;
	struct node_st *next;
};

#endif
