#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
/*
for_each ����:
����ԭ��:
�����㷨������������Ԫ��
for_each(beg, end, _func)
beg: ��ʼ������
end: ����������
_func: ������������

*/
// ����
void print01(int val) {
	cout << val << " ";
}
// �º���

class print02 {
public:
	void operator()(int val){
		cout << val << " ";
	}
};

void test_for_each() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	cout << "ʹ����ͨ�������� :" << endl;
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	cout << "ʹ�÷º������� :" << endl;
	for_each(v.begin(), v.end(), print02());
	cout << endl;


}

//int main() {
//	test_for_each();
//
//	system("pause");
//	return 0;
//}