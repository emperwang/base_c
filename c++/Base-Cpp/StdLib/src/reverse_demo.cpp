#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
����ԭ��:
reverse(beg, end)
��תָ����Χ��Ԫ��
beg:	��ʼ������
end:	����������
*/

void test_reverse() {
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);

	cout << " ��תǰ : " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	reverse(v.begin(), v.end());

	cout << " ��ת�� : " << endl;
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