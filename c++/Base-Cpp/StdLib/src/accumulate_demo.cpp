#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <numeric>

/*
accumulate:		��������Ԫ���ۼ��ܺ�
fill:			�����������Ԫ��
*/

/*
accumulate:
���ܣ�
��������������Ԫ���ۼ��ܺ�

����ԭ��:

accumulate(iterator beg, iterator end, value)
beg:	��ʼ������
end:	����������
value:	��ʼ�ۼ�ֵ
*/

void test_accumulate() {
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}

	int sum  = accumulate(v.begin(), v.end(), 0);
	cout << "sum = " << sum << endl;
}



//int main() {
//	test_accumulate();
//
//	system("pause");
//	return 0;
//}