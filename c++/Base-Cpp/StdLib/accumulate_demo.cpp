#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <numeric>

/*
accumulate:		计算容器元素累计总和
fill:			向容器中添加元素
*/

/*
accumulate:
功能：
计算区间内容器元素累计总和

函数原形:

accumulate(iterator beg, iterator end, value)
beg:	开始迭代器
end:	结束迭代器
value:	起始累加值
*/

void test_accumulate() {
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int sum  = accumulate(v.begin(), v.end(), 0);
	cout << "sum = " << sum << endl;
}



//int main() {
//	test_accumulate();
//
//	system("pause");
//	return 0;
//}