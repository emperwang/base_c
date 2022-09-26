#include <iostream>
#include <deque>

using namespace std;

/*
构造函数:

deque<T> deq;
deque(begin, end);	// 迭代器区间构造
deque(n, ele);		// n个元素的构造器
deque(const deque &deq);	// 拷贝构造函数
*/


/*
赋值操作
deque& operator=(const deque &deq);// 重载运算符  =
void assign(begin, end);	// 区间赋值
void assign(m,ele)			// n个元素赋值
*/

/*
empty()		// 判断是否为空
size()		// 元素个数
resize(size)	// 重新设置大小
resize(size, ele)	// 重新设置大小，并指定空间过大时的默认值填充值为ele
*/


/*
插入和删除操作
push_back(ele)		// 尾插法
push_front(ele)		// 头插法
pop_back()			// 尾删法
pop_front()			// 头删法

insert(pos, ele)		// 在pos位置插入一个元素
insert(pos, n, ele)		// 在pos位置插入n个元素ele
insert(pos, beg, end)	// 在pos位置插入 [beg， end)区间的元素
clear()					// 清空容器
erase(beg, end)			// 删除[beg, end) 区间的数据  返回下一个元素的位置
erase(pos)				// 删除pos位置的元素， 返回下一个元素的位置
*/

/*
数据存取:
at(int idx)			// 返回idx位置的元素
operator[](int idx)	// 返回索引位置的元素
front()				// 获取头元素
back()				// 获取尾元素
*/

/*
排序操作

sort(iterator beg, iterator end)		// 对beg 和 end区间的元素进行排序

*/
