#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
����ԭ��:
adjacent_find(iterator beg, iterator end)
���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
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
		cout << "û���ҵ�����Ԫ��" << endl;
	}
	else {
		cout << "�ҵ�Ԫ������ :" << *pos << endl;
	}
}


//int main() {
//	test_adjacent_find();
//
//	system("pause");
//	return 0;
//}