#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


/*
set_difference
����ԭ��:

set_difference(beg1, end1, beg2, end2, dest)
���������ϵĲ
ע�⣺�������ϱ�������������
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
	// Ŀ�꼯�ϣ�������  ��󼯺ϵ�Ԫ�ظ���
	vector<int> dest;
	dest.resize(max(v1.size(), v2.size()));

	set_difference(v1.begin(), v1.end(), v2.begin(),v2.end(),dest.begin());
	cout << " v1 �� v2�Ľ���" << endl;
	for_each(dest.begin(), dest.end(), set_difference_print);
	cout << endl;

	cout << " v2 �� v1�Ľ���" << endl;
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