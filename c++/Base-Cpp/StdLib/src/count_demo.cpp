#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
函数原形:

count(beg, end, value)
统计元素出现次数

beg:		开始迭代器
end:		结束迭代器
value:		要查找的元素
*/


// 查找内置类型
void test_count_interval() {

	vector<int> v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(50);
	v.push_back(70);

	int num = count(v.begin(), v.end(), 10);
	cout << "查找元素10 的个数 :" << num << endl;

}

class count_cus_type {
public:
	string name;
	int age;

	bool operator==(const count_cus_type &p) {
		if (this->name == p.name && this->age == p.age) {
			return true;
		}
		else {
			return false;
		}
	}

	count_cus_type(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

// 查找自定义类型
void test_count_cus_type() {
	vector<count_cus_type> v;
	count_cus_type c1("zhangsan", 20);
	count_cus_type c2("zhangsan", 20);
	count_cus_type c3("zhangsan", 20);
	count_cus_type c4("wangwu", 50);
	count_cus_type c5("lisi", 40);
	count_cus_type c6("zhaoliu", 60);
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);
	v.push_back(c5);
	v.push_back(c6);
	int num = count(v.begin(), v.end(), c1);
	cout << " 找到c1的个数 :" << num << endl;
}

//int main() {
//	test_count_interval();
//	test_count_cus_type();
//
//	system("pause");
//	return 0;
//}