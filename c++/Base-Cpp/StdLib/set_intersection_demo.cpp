#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
set_intersection	求两个容器的交集
set_union:			求两个容器的并集
set_difference:		求两个容器的差集
*/

/*
set_intersection(iterator beg1, end1, beg2, end2, dest)
求两个集合的交集
// 两个集合必须是有序序列

beg1		容器1开始迭代器
beg2		容器2开始迭代器
end1		容器1结束迭代器
end2		容器2结束迭代器
dest		目标容器迭代器
*/

void set_inter_print(int val) {
	cout << val << " ";
}

void test_set_intersection() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	// 目标集合
	vector<int> dest;
	// 先设置大小, 最坏情况是   最小的集合的个数
	dest.resize(min(v1.size(),v2.size()));
	vector<int>::iterator itEnd =  set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());

	for_each(dest.begin(), itEnd, set_inter_print);
	cout << endl;
}



//int main() {
//	test_set_intersection();
//
//	system("pause");
//	return 0;
//}