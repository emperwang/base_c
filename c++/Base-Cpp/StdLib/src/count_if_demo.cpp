#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
����ԭ��:
count_if(beg, end,_pred)
������ͳ��Ԫ�س��ִ���
beg:	��ʼ������
end:	����������
_pred:	ν��
*/

// �����������͵ĺ�������
class greater10 {
public:
	bool operator()(int val) {
		return val > 10;
	}
};

// ����������������
void test_count_if_interval() {
	vector<int> v;
	for (int i = 0; i < 20; i++) {
		v.push_back(i);
	}
	int num = count_if(v.begin(), v.end(), greater10());
	cout << "����10��Ԫ�ظ��� :" << num << endl;
}

class count_if_cus_type {
public:
	string name;
	int age;
	count_if_cus_type(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

// �Զ����������͵� ��������
class greater35 {
public:
	bool operator()(const count_if_cus_type &c) {
		
		return c.age > 35;
	}
};

// �����Զ�����������  �������20������
void test_count_if_cus_type() {
	vector<count_if_cus_type> v;
	count_if_cus_type c1("����", 10);
	count_if_cus_type c2("����", 40);
	count_if_cus_type c3("�ŷ�", 35);
	count_if_cus_type c4("����", 35);
	count_if_cus_type c5("����", 25);
	count_if_cus_type c6("��", 30);
	count_if_cus_type c7("����", 70);
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);
	v.push_back(c5);
	v.push_back(c6);
	v.push_back(c7);
	int num = count_if(v.begin(), v.end(), greater35());
	cout << " ����35������: " << num << endl;
}

//int main() {
//	test_count_if_interval();
//	test_count_if_cus_type();
//
//	system("pause");
//
//	return 0;
//}
