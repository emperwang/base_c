#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
replace:
����:
��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
����ԭ��:
replace(iterator beg, iterator end, oldvalue, newvalue)
*/

void replace_print_fun(int val) {
	cout << val << " ";
}

void test_replace() {
	vector<int> v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	
	replace(v.begin(), v.end(), 10, 100000);

	for_each(v.begin(), v.end(), replace_print_fun);
	cout << endl;
}


//int main() {
//	test_replace();
//
//	system("pause");
//	return 0;
//}