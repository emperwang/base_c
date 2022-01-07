#ifndef _SQLIST_H_
#define _SQLIST_H_
#include "struct.h"

sqlist *sqlist_create();
void sqlist_create2(sqlist **);
int sqlist_is_empty(sqlist *);
void sqlist_set_empty(sqlist *);
int sqlist_insert(sqlist*, int, datatype);
int sqlist_delete(sqlist*,int);
void sqlist_display(sqlist *);
int sqlist_find(sqlist *, datatype);
int sqlist_get(sqlist *, int, datatype);
void sqlist_destroy(sqlist *);
void sqlist_union(sqlist*, sqlist *);

#endif
