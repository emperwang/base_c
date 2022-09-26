#include <iostream>
#include <list>

using namespace std;

/*
构造函数
list<T> list;
list(begin, end)
list(n ,ele)
list(const list &list)
*/

/*
赋值和交换
assign(begin, end)
assign(n, ele)
list& operator=(const list &lst)
swap(list)
*/

/*
大小操作
size()
empty()
resize(num)
resize(num, ele)
*/


/*
插入和删除
push_back(ele)		// 尾插元素
pop_back()			// 尾删元素
push_front(ele)		// 头插元素
pop_front()			// 头删元素

insert(pos, ele)	// 在pos位置插入ele元素的拷贝
insert(pos, n, ele)	// 在pos位置插入n个ele元素
insert(pos, begin, end)	// 在pos位置插入[begin,end)区间元素

clear()		// 清空容器

erase(begin, end)	// 删除 [begin, end) 区间的元素， 返回下一个数据的位置
erase(pos)			// 删除pos位置的元素	返回下一个元素的位置
remove(ele)		// 删除容器中所有与ele匹配的元素

*/

/*
数据存取
front()		// 返回第一个元素
back()		// 返回最后一个元素

*/

/*
反转和排序
reverse()		// 反转链表
sort()			// 链表排序

*/

void printList(list<int> &li) {
	for (list<int>::iterator it = li.begin(); it != li.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// 自定义排序方式
bool  myCompare(int a, int b) {
	return a > b;
}

void testSort() {
	list<int> li;
	for (int i = 0; i < 10; i++) {
		int tmp =  rand() % 40 + 60;
		li.push_back(tmp);
	}
	cout << "反转前 : " << endl;
	printList(li);

	li.reverse();
	cout << " 反转后 : " << endl;
	printList(li);

	li.reverse();
	cout << "排序前 :" << endl;
	printList(li);

	cout << "排序后: " << endl;
	//li.sort();
	li.sort(myCompare);
	printList(li);
}

//int main() {
//	testSort();
//
//
//	system("pause");
//	return 0;
//}