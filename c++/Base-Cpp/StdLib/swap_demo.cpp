#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
swap:
功能:
互换两个容器的元素

函数原形:
swap(container c1, container c2)
互换两个容器的元素
*/

class swap_print_class {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void test_swap_algorithm() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "交换前 :" << endl;

	for_each(v1.begin(), v1.end(), swap_print_class());
	cout << endl;
	for_each(v2.begin(), v2.end(), swap_print_class());
	cout << endl;
	swap(v1, v2);

	cout << "交换后:" << endl;
	for_each(v1.begin(), v1.end(), swap_print_class());
	cout << endl;
	for_each(v2.begin(), v2.end(), swap_print_class());
	cout << endl;
}


//int main() {
//	test_swap_algorithm();
//
//	system("pause");
//	return 0;
//}