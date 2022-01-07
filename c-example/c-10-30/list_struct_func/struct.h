#ifndef _STRUCT_H_
#define	_STRUCT_H_
#define FORWARD 1
#define BACKWARD 2

typedef void llist_op(void *);
typedef int llist_cmp(const void *, const void *);

struct llist_node_st{
	struct llist_node_st *prev, *next;
	char data[0];
};

typedef struct llist_head{
	int size;
	struct llist_node_st head;
	int (*insert)(struct llist_head *, const void *data, int mode);
	void (*delete)(struct llist_head*, const void *key, llist_cmp *cmp);
	void*(*find)(struct llist_head *, const void *key, llist_cmp *cmp);
	int (*fetch)(struct llist_head *, const void *key, llist_cmp *cmp, void*);
	void (*travel)(struct llist_head *, llist_op *op);
}LLIST;

#endif
