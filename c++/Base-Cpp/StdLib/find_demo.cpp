#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
常用查找算法:
find				// 查找元素
find_if				// 按条件查找元素
adjacent_find		// 找到相邻重复元素
binary_search		// 二分查找
count				// 统计元素个数
count_if			// 按条件统计元素个数
*/

/*
find(iterator beg, iterator end, value)
按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
beg		开始迭代器
end		结束迭代器
value	查找的元素
*/

// find查找内置类型

void testInternalType() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 50);
	if (pos == v.end()){
		cout << "在容器中没有找到元素" << endl;
	}
	else {
		cout << "在容器中查找到元素 :" << *pos << endl;
	}

}

class cusComType {
public:
	string name;
	int age;
	// 使用find查找时, 需要重载==符号,不然find不知道如何是对自定义对象进行比较
	bool operator==(const cusComType &t) {
		if (this->name == t.name && this->age == t.age) {
			return true;
		}
		else {
			return false;
		}
	}

	cusComType(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

// find查找自定义类型
void testFindCusType() {
	vector<cusComType> v;
	cusComType c1("zhangsan", 30);
	cusComType c2("wnagwu", 50);
	cusComType c3("zhaoliu", 60);
	cusComType c4("zhouqi", 70);
	cusComType c5("lisi", 40);
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);
	v.push_back(c5);

	vector<cusComType>::iterator pos = find(v.begin(), v.end(), c2);
	if (pos == v.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "查找到元素, name = " << pos->name << ", age = " << pos->age << endl;
	}
}


//int main() {
//	// testInternalType();
//	testFindCusType();
//	system("pause");
//	return 0;
//}