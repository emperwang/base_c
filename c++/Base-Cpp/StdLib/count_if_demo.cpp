#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
函数原形:
count_if(beg, end,_pred)
按条件统计元素出现次数
beg:	开始迭代器
end:	结束迭代器
_pred:	谓词
*/

// 内置数据类型的函数对象
class greater10 {
public:
	bool operator()(int val) {
		return val > 10;
	}
};

// 测试内置数据类型
void test_count_if_interval() {
	vector<int> v;
	for (int i = 0; i < 20; i++) {
		v.push_back(i);
	}
	int num = count_if(v.begin(), v.end(), greater10());
	cout << "大于10的元素个数 :" << num << endl;
}

class count_if_cus_type {
public:
	string name;
	int age;
	count_if_cus_type(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

// 自定义数据类型的 函数对象
class greater35 {
public:
	bool operator()(const count_if_cus_type &c) {
		
		return c.age > 35;
	}
};

// 测试自定义数据类型  年龄大于20的人数
void test_count_if_cus_type() {
	vector<count_if_cus_type> v;
	count_if_cus_type c1("刘禅", 10);
	count_if_cus_type c2("刘备", 40);
	count_if_cus_type c3("张飞", 35);
	count_if_cus_type c4("关于", 35);
	count_if_cus_type c5("赵云", 25);
	count_if_cus_type c6("马超", 30);
	count_if_cus_type c7("黄忠", 70);
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);
	v.push_back(c5);
	v.push_back(c6);
	v.push_back(c7);
	int num = count_if(v.begin(), v.end(), greater35());
	cout << " 大于35的人数: " << num << endl;
}

//int main() {
//	test_count_if_interval();
//	test_count_if_cus_type();
//
//	system("pause");
//
//	return 0;
//}
