#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 自定义一元谓词
// 大于5的值
class greaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void testPredOne() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// 查找容器中是否有大于5的值
	// greaterFive()称为匿名对象
	vector<int>::iterator val =  find_if(v.begin(), v.end(),greaterFive() );
	if (val == v.end()) { // 等于end  表示没有找到
		cout << "不存在此类元素" << endl;
	}
	else {
		cout << "存在此元素，值为: " << *val << endl;
	}
}


//int main() {
//	testPredOne();
//
//
//	system("pause");
//	return 0;
//}