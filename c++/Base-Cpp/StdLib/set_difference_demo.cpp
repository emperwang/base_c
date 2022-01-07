#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


/*
set_difference
函数原形:

set_difference(beg1, end1, beg2, end2, dest)
求两个集合的差集
注意：两个集合必须是有序序列
*/

void set_difference_print(int val) {
	cout << val << " ";
}

void test_set_difference() {
	vector<int> v1, v2;
	for (int i = 1; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	// 目标集合，最坏情况是  最大集合的元素个数
	vector<int> dest;
	dest.resize(max(v1.size(), v2.size()));

	set_difference(v1.begin(), v1.end(), v2.begin(),v2.end(),dest.begin());
	cout << " v1 和 v2的交集" << endl;
	for_each(dest.begin(), dest.end(), set_difference_print);
	cout << endl;

	cout << " v2 和 v1的交集" << endl;
	set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), dest.begin());
	for_each(dest.begin(), dest.end(), set_difference_print);
	cout << endl;
}

//int main() {
//	test_set_difference();
//
//	system("pause");
//	return 0;
//}