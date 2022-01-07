#include <iostream>
#include "SingleList.h"

using namespace std;

// 初始化链表
void init(HEAD *head) {
	head->first = NULL;
	head->size = 0;
}

// 添加节点
void appendValue(HEAD *head, int val) {
	snode *node = (snode *)malloc(sizeof(snode));
	node->val = val;
	node->next = NULL;
	if (head->first == NULL) {
		head->first = node;
	}
	else {
		snode *tmp = head->first;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = node;
	}
	head->size++;
}

// 遍历链表
void travleList(HEAD *head) {
	if (head->size <= 0) {
		cout << "链表没有可用的元素." << endl;
		return;
	}
	cout << "元素个数为: " << head->size << endl;
	snode *tmp = head->first;
	while (tmp->next != NULL) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << tmp->val << " ";
	cout << endl;
}

// 开头处添加节点
void headInsertValue(HEAD *head, int val) {
	snode *ival = (snode *)malloc(sizeof(snode));
	ival->val = val;
	snode *tmp = head->first;
	ival->next = tmp;
	head->first = ival;
	head->size++;
}

// 指定位置添加节点
void posInsertValue(HEAD *head, int pos, int val) {
	if (head->size <= pos) { // 大于链表的元素, 则直接在最后追加
		appendValue(head, val);
	}
	else {	// 找到位置进行插入
		int idx = 0;
		snode *ival = (snode *)malloc(sizeof(snode));
		ival->val = val;
		snode *fid = head->first;
		snode *pre = NULL;
		while ((idx++) < pos) {
			pre = fid;
			fid = fid->next;
		}
		ival->next = fid;
		pre->next = ival;
		head->size++;
	}
}

// 删除出现的第一个节点
void deleteValue(HEAD *head, int val) {
	if (!isEmpty(head)) {
		snode *pre = NULL, *node = head->first;
		// 头结点删除
		if (val == node->val) {
			head->first = node->next;
			head->size--;
			free(node);
			return;
		}
		// 其他节点删除
		pre = node;
		node = node->next;
		while (node != NULL) {
			if (node->val == val) {
				// cout << "== pre=" << pre->val << ",node=" << node->val << endl;
				pre->next = node->next;
				free(node);
				head->size--;
				break;
			}
			else {
				// cout << "else :" << "pre=" << pre->val << ",node=" << node->val << endl;
				pre = pre->next;
				node = node->next;
			}
		}
	}
	else {
		cout << "不存在元素 :" << val << endl;
	}
}
// 删除链表中 值为val的所有元素
void deleteAllVal(HEAD *head, int val) {
	if (!isEmpty(head)) {
		snode *pre = NULL, *node = head->first;
		// 头结点删除
		if (val == node->val) {
			head->first = node->next;
			head->size--;
			free(node);
		}
		// 其他节点删除
		pre = node;
		node = node->next;
		while (node != NULL) {
			if (node->val == val) {
				// cout << "== pre=" << pre->val << ",node=" << node->val << endl;
				pre->next = node->next;
				free(node);
				head->size--;
				node = pre->next;
			}
			else {
				// cout << "else :" << "pre=" << pre->val << ",node=" << node->val << endl;
				pre = pre->next;
				node = node->next;
			}
		}
	}
	else {
		cout << "不存在元素 :" << val << endl;
	}
}


// 查找链表中是否存在 值为val的元素
bool findValue(HEAD *head, int val) {
	if (!isEmpty(head)) {
		snode *l = head->first;
		while (l != NULL) {
			if (l->val == val) {
				return true;
			}
			else {
				l = l->next;
			}
		}
	}
	else {
		cout << "链表为空，不包含此元素:" << val << endl;
	}
}

// 链表是否为空  为空返回true， 不为空 返回0
bool isEmpty(HEAD *head) {
	return head->first == NULL;
}

// 获取链表元素个数
int listSize(HEAD *head) {
	return head->size;
}
