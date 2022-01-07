#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__

// ���������ʵ��
typedef struct sing_node {
	int val;
	struct sing_node *next;
}snode;

typedef struct node_list {
	int size;
	struct sing_node *first;
}HEAD;

// ��ʼ������
void init(HEAD *);

// ��β����ӽڵ�
void appendValue(HEAD *, int val);

// ��ͷ����ӽڵ�
void headInsertValue(HEAD *head, int val);

// ָ��λ����ӽڵ�
void posInsertValue(HEAD *head, int pos, int val);

// ��������
void travleList(HEAD *);

// ɾ�����ֵĵ�һ���ڵ�
void deleteValue(HEAD *, int val);
// ɾ�������� ֵΪval������Ԫ��
void deleteAllVal(HEAD *, int val);

// �����������Ƿ���� ֵΪval��Ԫ��
bool findValue(HEAD *head, int val);

// �����Ƿ�Ϊ��
bool isEmpty(HEAD *head);

// ��ȡ����Ԫ�ظ���
int listSize(HEAD *head);

// ��ת����

// ������Ԫ�ؽ�������

#endif // !__SINGLELIST_H__