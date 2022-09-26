#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
set_union:			求两个容器的并集

函数原形:
set_union(beg1,end1, beg2, end2, dest)
求两个集合的并集
注意： 两个集合必须是有序序列
*/

void set_union_print(int val) {
	cout << val << " ";
}

void test_set_union() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	// 目标集合，最坏情况是  两个集合相加
	vector<int> dest;
	dest.resize(v1.size() + v2.size());

	vector<int>::iterator itEnd =  set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());

	//for_each(dest.begin(), dest.end(), set_union_print);
	for_each(dest.begin(), itEnd, set_union_print);
	cout << endl;

}

//int main() {
//	test_set_union();
//
//	system("pause");
//	return 0;
//}
