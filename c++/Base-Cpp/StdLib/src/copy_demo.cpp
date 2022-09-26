#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
常用的拷贝和替换算法:
copy:			容器内指定范围的元素拷贝到另一个容器中
replace:		将容器内指定范围的旧元素修改为新元素
replace_if:		容器内指定范围满足条件的元素替换为新元素
swap:			互换两个容器的元素
*/

/*
copy:
功能:
将容器内指定范围的元素拷贝到另一个容器中

函数原形:
copy(iterator beg, iterator end, iterator dest)
按值查找元素, 找到返回指定位置迭代器, 找不到返回结束迭代器
beg		源容器开始迭代器
end		源容器结束迭代器
dest	目标容器开始迭代器
*/

class m_copy_print {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void test_copy() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), m_copy_print());
	cout << endl;
}

//int main() {
//	test_copy();
//
//	system("pause");
//	return 0;
//}