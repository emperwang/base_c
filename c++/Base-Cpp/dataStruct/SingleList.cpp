#include <iostream>
#include "SingleList.h"

using namespace std;

// ��ʼ������
void init(HEAD *head) {
	head->first = NULL;
	head->size = 0;
}

// ��ӽڵ�
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

// ��������
void travleList(HEAD *head) {
	if (head->size <= 0) {
		cout << "����û�п��õ�Ԫ��." << endl;
		return;
	}
	cout << "Ԫ�ظ���Ϊ: " << head->size << endl;
	snode *tmp = head->first;
	while (tmp->next != NULL) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << tmp->val << " ";
	cout << endl;
}

// ��ͷ����ӽڵ�
void headInsertValue(HEAD *head, int val) {
	snode *ival = (snode *)malloc(sizeof(snode));
	ival->val = val;
	snode *tmp = head->first;
	ival->next = tmp;
	head->first = ival;
	head->size++;
}

// ָ��λ����ӽڵ�
void posInsertValue(HEAD *head, int pos, int val) {
	if (head->size <= pos) { // ���������Ԫ��, ��ֱ�������׷��
		appendValue(head, val);
	}
	else {	// �ҵ�λ�ý��в���
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

// ɾ�����ֵĵ�һ���ڵ�
void deleteValue(HEAD *head, int val) {
	if (!isEmpty(head)) {
		snode *pre = NULL, *node = head->first;
		// ͷ���ɾ��
		if (val == node->val) {
			head->first = node->next;
			head->size--;
			free(node);
			return;
		}
		// �����ڵ�ɾ��
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
		cout << "������Ԫ�� :" << val << endl;
	}
}
// ɾ�������� ֵΪval������Ԫ��
void deleteAllVal(HEAD *head, int val) {
	if (!isEmpty(head)) {
		snode *pre = NULL, *node = head->first;
		// ͷ���ɾ��
		if (val == node->val) {
			head->first = node->next;
			head->size--;
			free(node);
		}
		// �����ڵ�ɾ��
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
		cout << "������Ԫ�� :" << val << endl;
	}
}


// �����������Ƿ���� ֵΪval��Ԫ��
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
		cout << "����Ϊ�գ���������Ԫ��:" << val << endl;
	}
}

// �����Ƿ�Ϊ��  Ϊ�շ���true�� ��Ϊ�� ����0
bool isEmpty(HEAD *head) {
	return head->first == NULL;
}

// ��ȡ����Ԫ�ظ���
int listSize(HEAD *head) {
	return head->size;
}
