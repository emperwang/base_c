#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <algorithm>
// ʹ�ú�������ı�sort��Ĭ���������
class m_pred_compare {
public:
	bool operator()(int val1, int val2) {
		return  val1 > val2;
	}
};

// ʹ���Զ��� ��������  �ı��������������
void test_pred_two() {
	vector<int> v1;
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(10);
	v1.push_back(50);
	v1.push_back(40);
	sort(v1.begin(), v1.end());
	cout << "Ĭ������: " << endl;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// ���������޸��������
	sort(v1.begin(), v1.end(), m_pred_compare());
	cout << "�Զ����������: " << endl;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


//int main() {
//	test_pred_two();
//
//
//	system("pause");
//	return 0;
//}