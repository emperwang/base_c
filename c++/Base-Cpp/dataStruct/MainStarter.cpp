#include <iostream>
#include "SingleList.h"
#include "Queue.h"
using namespace std;

// 测试单向链表
void testSingleList();
// 测试双向链表

// 测试queue 队列
void testQueue();

// 测试栈


void testPoint() {
	int tmp = 5;
	int *p = &tmp;
	int *p1 = p;
	*p = 10;
	cout << "p = " << *p << ", p1=" << *p1 << endl;
}

int main() {
	//testPoint();
	//testSingleList();
	testQueue();

	system("pause");
	return 0;
}

void testQueue() {
	Qlist *q = (Qlist*)malloc(sizeof(Qlist));;
	initQueue(q);
	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 30);
	enQueue(q, 40);
	cout << "outQueue:" << outQueue(q) << endl;
	travelQueue(q);
	reTravelQueue(q);
	cout << "size:" << q->size << endl;
}

void testSingleList() {
	HEAD *head = (HEAD *)malloc(sizeof(HEAD));
	init(head);
	appendValue(head, 10);
	appendValue(head, 10);
	appendValue(head, 10);
	//appendValue(head, 40);
	headInsertValue(head, 5);
	posInsertValue(head, 2, 15);
	posInsertValue(head, 100, 50);

	//deleteValue(head, 50);
	//deleteAllVal(head, 10);
	cout << "是否存在元素50 :" << findValue(head, 50)<< endl;
	travleList(head);

	// 是否为空
	// 大小
	cout << "是否为空: " << isEmpty(head) << ",  元素个数为: " << listSize(head) << endl;
}