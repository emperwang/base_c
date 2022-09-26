#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
函数原形:
reverse(beg, end)
反转指定范围的元素
beg:	开始迭代器
end:	结束迭代器
*/

void test_reverse() {
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);

	cout << " 反转前 : " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	reverse(v.begin(), v.end());

	cout << " 反转后 : " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}

//int main() {
//	test_reverse();
//
//	system("pause");
//	return 0;
//}