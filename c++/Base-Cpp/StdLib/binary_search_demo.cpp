#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
函数原形:
binary_search(iteratr begin, iterator end, value)
找到返回true，否则返回false;  前提容器必须有序
begin:	开始迭代器
end:	结束迭代器
value:  要查找的值
*/

void test_binary_search() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret) {
		cout << "找到元素 " << endl;
	}
	else {
		cout << "没有找到元素 .." << endl;
	}
}


//int main() {
//	test_binary_search();
//
//	system("pause");
//	return 0;
//}