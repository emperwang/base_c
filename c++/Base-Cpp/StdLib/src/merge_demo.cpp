#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
����ԭ��:
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
�����ϲ����������洢����һ��������
�˺ϲ���Ҫ����1������2���������������ϲ���������ȻΪ��������

beg1:	����1�Ŀ�ʼ������
end1:	����1�Ľ���������

beg2:	����2�Ŀ�ʼ������
end2:	����2�Ľ���������

dest:	Ŀ�������ĵ�����
*/


void test_merge() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	// Ŀ������:
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