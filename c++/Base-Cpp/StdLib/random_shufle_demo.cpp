#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

/*
����ԭ��:
random_shuffle(beg, end)
��ָ����Χ�ڵ�Ԫ�������������
*/

void test_random_shuffle() {
	// ʱ��ʱ����Ϊ�������
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	random_shuffle(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


//int main() {
//	test_random_shuffle();
//	system("pause");
//	return 0;
//}