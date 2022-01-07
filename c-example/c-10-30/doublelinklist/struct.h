#ifndef _STRUCT_H_
#define _STRUCT_H_

#define FORWARD 1
#define BACKWARD 2

typedef void llist_op(void *);
typedef int llist_cmp(const void *, const void *);

struct llist_node_st{
	void *data;
	struct llist_node_st *prev,*next;
};

typedef struct{
	int size;
	struct llist_node_st  head;

}LLIST;


#endif
