#include <iostream>
#include <malloc.h>
#include "Queue.h"

using namespace std;

// ��ʼ��һ���ж�
void initQueue(Qlist *list) {
	list->head = list->end = NULL;
	list->size = 0;
}

// 1.�Ӷ���ͷ������
void enQueue(Qlist *list, int val) {
	Qnode *node = (Qnode*)malloc(sizeof(Qnode));
	node->val = val;
	node->pre = NULL;
	if (list->head == NULL) {	// ��һ�β���
		list->head = list->end = node;
		node->next = NULL;
	}
	else {
		node->next = list->head;
		list->head->pre = node;
		list->head = node;
	}
	list->size++;
}

// 2.���ӣ���ȡ����β�Ľڵ�
int outQueue(Qlist *list) {
	if (!isEmpty(list)) {
		int val = list->end->val;
		Qnode *ll = list->end;
		list->end = list->end->pre;
		list->end->next = NULL;
		list->size--;
		free(ll);
		return val;
	}
	return -1;
}

// 3.�����������
void travelQueue(Qlist *list) {
	if (!isEmpty(list)) {
		Qnode * node = list->head;
		while (node != NULL) {
			cout << node->val << " ";
			node = node->next;
		}
		cout << endl;
	}
}
// �����������
void reTravelQueue(Qlist *list) {
	if (!isEmpty(list)) {
		Qnode *node = list->end;
		while (node != NULL) {
			cout << node->val << " ";
			node = node->pre;
		}
		cout << endl;
	}

}

// 4.����Ԫ�ظ���
int getQueueSize(Qlist *list) {
	return list->size;
}

// 5.�����Ƿ�Ϊ��
bool isEmpty(Qlist *list) {
	return list->head == NULL && list->end == NULL && list->size == 0;
}