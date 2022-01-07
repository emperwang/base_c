#ifndef _SEQUEUE_H_
#define _SEQUEUE_H_
#include "struct.h"

sequeue *sequeue_create();

int sequeue_enqueue(sequeue *,type);
int sequeue_dequeue(sequeue *, type);
int sequeue_is_empty(sequeue *);
void sequeue_display(sequeue *);
void sequeue_clear(sequeue *);


#endif
