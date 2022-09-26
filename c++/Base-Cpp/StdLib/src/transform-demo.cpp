#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// transform  算法
/*
功能:
搬运容器到同一个容器中

函数原形:
transform(iterator begin1, iterator end1, iterator begin2, _func)
beign1: 源容器开始迭代器 
end1: 源容器结束迭代器
beign2:	目标容器开始迭代器
_func: 函数或者函数对象

*/

class mTransform {
public :
	int operator()(int val) {
		//return val;
		return val + 100;
	}
};

class mprint {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void testTransform() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	vector<int> target;
	target.resize(v.size()); // 注意: 目标容器需要先开辟空间,不然会失败
	transform(v.begin(), v.end(), target.begin(), mTransform());

	for_each(target.begin(), target.end(), mprint());
	cout << endl;
}

//int main() {
//	testTransform();
//
//	system("pause");
//	return 0;
//}