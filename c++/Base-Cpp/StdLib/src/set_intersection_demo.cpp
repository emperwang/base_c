#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
set_intersection	�����������Ľ���
set_union:			�����������Ĳ���
set_difference:		�����������Ĳ
*/

/*
set_intersection(iterator beg1, end1, beg2, end2, dest)
���������ϵĽ���
// �������ϱ�������������

beg1		����1��ʼ������
beg2		����2��ʼ������
end1		����1����������
end2		����2����������
dest		Ŀ������������
*/

void set_inter_print(int val) {
	cout << val << " ";
}

void test_set_intersection() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	// Ŀ�꼯��
	vector<int> dest;
	// �����ô�С, ������   ��С�ļ��ϵĸ���
	dest.resize(min(v1.size(),v2.size()));
	vector<int>::iterator itEnd =  set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), dest.begin());

	for_each(dest.begin(), itEnd, set_inter_print);
	cout << endl;
}



//int main() {
//	test_set_intersection();
//
//	system("pause");
//	return 0;
//}