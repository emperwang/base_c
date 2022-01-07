#include <iostream>
#include <map>

using namespace std;


/*
构造器
map<T1,T2> mp;
map(const map &mp)

赋值:
map& operator=(const map &mp)
*/

/*
大小和交换
size()
empty()

swap(st)	// 交换两个集合的容器

*/

/*
插入和删除
insert(ele)			// 插入元素
clear()				// 清空容器
erase(pos)			// 删除pos迭代器所指的元素
erase(begin, end)	// 删除区间[begin,end) 的所有元素

erase(key)		// 删除容器中值为key的元素

*/

/*
查找和统计
find(key)	// 查找key是否存在,存在则返回其迭代器; 不存在返回  end()
count(key)  // 统计key的元素个数

*/

/*
排序

*/
// 自定义排序仿函数
class m_map_sort {
public: 
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};


void test_map_sort() {
	map<int, int> mp;
	mp.insert(make_pair(1, 20));
	mp.insert(make_pair(2, 70));
	mp.insert(make_pair(6, 60));
	mp.insert(make_pair(5, 30));
	mp.insert(make_pair(4, 10));
	mp.insert(make_pair(3, 40));
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << "key : " << it->first << ", val :" << it->second << endl;
	}
	cout << " 自定义排序 :" << endl;
	map<int, int, m_map_sort> mp1;
	mp1.insert(make_pair(1, 20));
	mp1.insert(make_pair(2, 70));
	mp1.insert(make_pair(6, 60));
	mp1.insert(make_pair(5, 30));
	mp1.insert(make_pair(4, 10));
	mp1.insert(make_pair(3, 40));
	for (map<int, int, m_map_sort>::iterator it = mp1.begin(); it != mp1.end(); it++) {
		cout << "key : " << it->first << ", val :" << it->second << endl;
	}
}

//int main() {
//	test_map_sort();
//
//	system("pause");
//	return 0;
//}