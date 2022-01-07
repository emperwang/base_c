#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
函数原形:
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
容器合并操作，并存储到另一个容器中
此合并需要容器1和容器2都是有序容器，合并后容器仍然为有序容器

beg1:	容器1的开始迭代器
end1:	容器1的结束迭代器

beg2:	容器2的开始迭代器
end2:	容器2的结束迭代器

dest:	目标容器的迭代器
*/


void test_merge() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	// 目标容器:
	vector<int> dest;
	dest.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());

	for (vector<int>::iterator it = dest.begin(); it != dest.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//int main() {
//	test_merge();
//
//	system("pause");
//	return 0;
//}