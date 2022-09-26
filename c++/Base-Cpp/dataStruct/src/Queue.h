#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct qnode{
	int val;
	struct qnode *pre, *next;
}Qnode;

typedef struct qlist {
	int size;
	struct qnode *head, *end;
}Qlist;

void initQueue(Qlist *list);

// 1.从对列头入队入队
void enQueue(Qlist *list, int val);

// 2.出队，获取队列尾的节点
int outQueue(Qlist *list);

// 3.遍历队列
void travelQueue(Qlist *list);

void reTravelQueue(Qlist *list);

// 4.队列元素个数
int getQueueSize(Qlist *list);

// 5.队列是否为空
bool isEmpty(Qlist *list);

#endif // !__QUEUE_H__