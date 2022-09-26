#include <iostream>
#include <malloc.h>
#include "Queue.h"

using namespace std;

// 初始化一个列队
void initQueue(Qlist *list) {
	list->head = list->end = NULL;
	list->size = 0;
}

// 1.从对列头入队入队
void enQueue(Qlist *list, int val) {
	Qnode *node = (Qnode*)malloc(sizeof(Qnode));
	node->val = val;
	node->pre = NULL;
	if (list->head == NULL) {	// 第一次插入
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

// 2.出队，获取队列尾的节点
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

// 3.正序遍历队列
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
// 反向遍历队列
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

// 4.队列元素个数
int getQueueSize(Qlist *list) {
	return list->size;
}

// 5.队列是否为空
bool isEmpty(Qlist *list) {
	return list->head == NULL && list->end == NULL && list->size == 0;
}