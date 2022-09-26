#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
/*
for_each 遍历:
函数原形:
遍历算法，遍历容器中元素
for_each(beg, end, _func)
beg: 开始迭代器
end: 结束迭代器
_func: 函数或函数对象

*/
// 函数
void print01(int val) {
	cout << val << " ";
}
// 仿函数

class print02 {
public:
	void operator()(int val){
		cout << val << " ";
	}
};

void test_for_each() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	cout << "使用普通函数遍历 :" << endl;
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	cout << "使用仿函数遍历 :" << endl;
	for_each(v.begin(), v.end(), print02());
	cout << endl;


}

//int main() {
//	test_for_each();
//
//	system("pause");
//	return 0;
//}