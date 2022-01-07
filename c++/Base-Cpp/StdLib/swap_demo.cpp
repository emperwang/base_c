#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
swap:
����:
��������������Ԫ��

����ԭ��:
swap(container c1, container c2)
��������������Ԫ��
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

	cout << "����ǰ :" << endl;

	for_each(v1.begin(), v1.end(), swap_print_class());
	cout << endl;
	for_each(v2.begin(), v2.end(), swap_print_class());
	cout << endl;
	swap(v1, v2);

	cout << "������:" << endl;
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