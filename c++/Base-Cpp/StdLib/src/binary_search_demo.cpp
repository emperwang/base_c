#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
����ԭ��:
binary_search(iteratr begin, iterator end, value)
�ҵ�����true�����򷵻�false;  ǰ��������������
begin:	��ʼ������
end:	����������
value:  Ҫ���ҵ�ֵ
*/

void test_binary_search() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	bool ret = binary_search(v.begin(), v.end(), 5);
	if (ret) {
		cout << "�ҵ�Ԫ�� " << endl;
	}
	else {
		cout << "û���ҵ�Ԫ�� .." << endl;
	}
}


//int main() {
//	test_binary_search();
//
//	system("pause");
//	return 0;
//}