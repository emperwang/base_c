#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__

// 单向链表的实现
typedef struct sing_node {
	int val;
	struct sing_node *next;
}snode;

typedef struct node_list {
	int size;
	struct sing_node *first;
}HEAD;

// 初始化链表
void init(HEAD *);

// 结尾处添加节点
void appendValue(HEAD *, int val);

// 开头处添加节点
void headInsertValue(HEAD *head, int val);

// 指定位置添加节点
void posInsertValue(HEAD *head, int pos, int val);

// 遍历链表
void travleList(HEAD *);

// 删除出现的第一个节点
void deleteValue(HEAD *, int val);
// 删除链表中 值为val的所有元素
void deleteAllVal(HEAD *, int val);

// 查找链表中是否存在 值为val的元素
bool findValue(HEAD *head, int val);

// 链表是否为空
bool isEmpty(HEAD *head);

// 获取链表元素个数
int listSize(HEAD *head);

// 反转链表

// 对链表元素进行排序

#endif // !__SINGLELIST_H__