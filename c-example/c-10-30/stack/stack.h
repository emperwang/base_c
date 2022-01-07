#ifndef _STACK_H_ 
#define _STACK_H_
#include "struct.h"

sqstack *sqstack_create();
int sqstack_push(sqstack *,type);
int sqstack_pop(sqstack *, type);
int sqstack_top(sqstack *, type);
int sqstack_is_empty(sqstack *);
void sqstack_display(sqstack *);

#endif
