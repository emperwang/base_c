#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
���õĿ������滻�㷨:
copy:			������ָ����Χ��Ԫ�ؿ�������һ��������
replace:		��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
replace_if:		������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
swap:			��������������Ԫ��
*/

/*
copy:
����:
��������ָ����Χ��Ԫ�ؿ�������һ��������

����ԭ��:
copy(iterator beg, iterator end, iterator dest)
��ֵ����Ԫ��, �ҵ�����ָ��λ�õ�����, �Ҳ������ؽ���������
beg		Դ������ʼ������
end		Դ��������������
dest	Ŀ��������ʼ������
*/

class m_copy_print {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void test_copy() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), m_copy_print());
	cout << endl;
}

//int main() {
//	test_copy();
//
//	system("pause");
//	return 0;
//}