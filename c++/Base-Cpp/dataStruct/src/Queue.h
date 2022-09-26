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

// 1.�Ӷ���ͷ������
void enQueue(Qlist *list, int val);

// 2.���ӣ���ȡ����β�Ľڵ�
int outQueue(Qlist *list);

// 3.��������
void travelQueue(Qlist *list);

void reTravelQueue(Qlist *list);

// 4.����Ԫ�ظ���
int getQueueSize(Qlist *list);

// 5.�����Ƿ�Ϊ��
bool isEmpty(Qlist *list);

#endif // !__QUEUE_H__