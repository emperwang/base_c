#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
函数原形:
adjacent_find(iterator beg, iterator end)
查找相邻重复元素，返回相邻元素的第一个位置的迭代器
*/

void test_adjacent_find() {
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(9);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end()) {
		cout << "没有找到相邻元素" << endl;
	}
	else {
		cout << "找到元相邻素 :" << *pos << endl;
	}
}


//int main() {
//	test_adjacent_find();
//
//	system("pause");
//	return 0;
//}