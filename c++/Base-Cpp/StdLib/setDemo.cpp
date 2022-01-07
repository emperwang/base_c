#include <iostream>
#include <set>

using namespace std;

/*
构造函数
set<T> s;
set(const set& st)

赋值
set& operator=(const set &st);

*/

/*
大小和交换
size()		// 返回容器中元素的个数
empty()		// 判断容器是否为空
swap(st)	// 交换连个集合容器

*/

/*
插入和删除
insert(ele)		// 在容器中插入元素
clear()			// 清空容器
erase(pos)		//删除pos迭代器所指元素，并返回下一个元素的迭代器
erase(begin, end)	// 删除 [begin,end) 的所有元素，返回下一个元素的迭代器
erase(ele)			// 删除容器中值为ele的元素
*/

/*
查找和统计
find(key)		// 查找key是否存在，若存在，返回此元素的迭代器； 不存在，则返回 set.end()
count(key)		// 统计key的元素个数
*/


/*
set 和 multiset区别:
set 不可以插入重复数据，multiset可以
set插入数据的同时会返回插入结果，表示插入是否成功
multiset 不会检测数据， 因此可以重复插入数据
*/

void testInsert() {
	set<int> st;
	pair<set<int>::iterator, bool> ret = st.insert(10);

	if (ret.second) {
		cout << " 第一次插入成功" << endl;
	}
	else {
		cout << "第一次插入失败 " << endl;
	}

	ret = st.insert(10);
	if(ret.second) {
		cout << " 第一次插入成功" << endl;
	}
	else {
		cout << "第一次插入失败 " << endl;
	}

	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}

// 自定义排序仿函数
class m_compare_Set {
public:
	bool operator()(int v, int v2) {
		return v > v2;
	}
};

void printSet(const set<int> &st) {
	for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// 测试set自定义的排序
void testCusSort() {
	set<int> st1;
	st1.insert(10);
	st1.insert(50);
	st1.insert(30);
	st1.insert(40);
	st1.insert(20);
	cout << "默认排序 : " << endl;
	printSet(st1);

	set<int, m_compare_Set> st2;
	st2.insert(10);
	st2.insert(50);
	st2.insert(30);
	st2.insert(40);
	st2.insert(20);
	cout << "自定义排序 :" << endl;
	for (set<int, m_compare_Set>::iterator it = st2.begin(); it != st2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//int main() {
//	//testInsert();
//	testCusSort();
//
//	system("pause");
//	return 0;
//}