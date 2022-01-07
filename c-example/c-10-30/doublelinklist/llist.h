#ifndef _LLIST_H_
#define _LLIST_H_
#include "struct.h"

LLIST *llist_create(int size);
int llist_insert(LLIST*, const void *data, int mode);
void llist_delete(LLIST *, const void *key, llist_cmp *cmp);
void *llist_find(LLIST *, const void *key, llist_cmp *cmp);
int llist_fetch(LLIST *, const void *key, llist_cmp *cmp, void *);

void llist_travel(LLIST *, llist_op *op);

#endif
