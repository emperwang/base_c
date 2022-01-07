#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <string>
/*
函数原形:
find_if(iterator beg, iterator end, _pred)
按值查找元素,找到返回指定位置迭代器, 找不到返回结束迭代器位置
beg;	开始迭代器
end:	结束迭代器
_pred:	函数或函数对象(返回bool类型的仿函数)
*/

class find_if_interCom {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

// 内置类型测试
void testInterFind_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(), find_if_interCom());
	if (pos == v.end()) {
		cout << "没有找到 .." << endl;
	}
	else {
		cout << "找到元素，值为: " << *pos << endl;
	}

}


class find_cus_type {
public:
	string name;
	int age;

	find_cus_type(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

// 自定义类型函数对象
// 定义查找年龄大于20的对象
class find_cus_type_com {
public:
	bool operator()(const find_cus_type &p) {
		return p.age > 30;
	}
};


// 自定义类型测试
void test_find_if_cus_type() {
	find_cus_type f1("刘备", 35);
	find_cus_type f2("关羽", 35);
	find_cus_type f3("张飞", 35);
	find_cus_type f4("赵云", 25);
	find_cus_type f5("曹操", 45);
	vector<find_cus_type> v1;
	v1.push_back(f1);
	v1.push_back(f2);
	v1.push_back(f3);
	v1.push_back(f4);
	v1.push_back(f5);

	vector<find_cus_type>::iterator pos = find_if(v1.begin(), v1.end(), find_cus_type_com());
	if (pos == v1.end()) {
		cout << "没有找到. " << endl;
	}
	else {
		cout << "元素找到, name= " << pos->name << ", age = " << pos->age << endl;
	}
}


//int main() {
//	//testInterFind_if();
//	test_find_if_cus_type();
//	system("pause");
//	return 0;
//}