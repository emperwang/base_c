#ifndef __LIST_H__
#define __LIST_H__

#define null (void*)0
typedef struct listNode{
	struct listNode *prev;
	struct listNode *next;
	void *value;
}listNode;

typedef struct listIter{
	listNode *next;
	int direction;	
}listIter;

typedef struct list{
	listNode *head;
	listNode *tail;
	void *(*dup)(void *ptr);
	void (*free)(void *ptr);
	int (*match)(void *ptr,void *key);
	unsigned int len;		
}list;

/*functions  implemented  as macros*/
#define listLenth(l) ((l)->len)
#define listFirst(l) ((l)->head)
#define listLast(l)	 ((l)->tail)
#define listPrevNode(n) ((n)->prev)
#define listNextNode(n)	((n)->next)
#define listNodeValue(n) ((n)->value)

#define listSetDupMethod(l,m)	((l)->dup = (m))
#define listSetFreeMethod(l,m)	((l)->free = (m))
#define listSetMatchMethod(l,m)	((l)->match = (m))

#define listGetDupMethod(l)  ((l)->dup)
#define listGetFree(l)	((l)->free)
#define listGetMatchMethod(l)	((l)->match)

// prototypes
list *listCreate();
void printList(list *list);
list *listAddNodeHead(list *list, void *value);
list *listAddNodeTail(list *list, void *value);


#endif