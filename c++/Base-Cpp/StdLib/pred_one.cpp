#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// �Զ���һԪν��
// ����5��ֵ
class greaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void testPredOne() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// �����������Ƿ��д���5��ֵ
	// greaterFive()��Ϊ��������
	vector<int>::iterator val =  find_if(v.begin(), v.end(),greaterFive() );
	if (val == v.end()) { // ����end  ��ʾû���ҵ�
		cout << "�����ڴ���Ԫ��" << endl;
	}
	else {
		cout << "���ڴ�Ԫ�أ�ֵΪ: " << *val << endl;
	}
}


//int main() {
//	testPredOne();
//
//
//	system("pause");
//	return 0;
//}