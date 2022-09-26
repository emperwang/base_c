#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <string>
/*
����ԭ��:
find_if(iterator beg, iterator end, _pred)
��ֵ����Ԫ��,�ҵ�����ָ��λ�õ�����, �Ҳ������ؽ���������λ��
beg;	��ʼ������
end:	����������
_pred:	������������(����bool���͵ķº���)
*/

class find_if_interCom {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

// �������Ͳ���
void testInterFind_if() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(), find_if_interCom());
	if (pos == v.end()) {
		cout << "û���ҵ� .." << endl;
	}
	else {
		cout << "�ҵ�Ԫ�أ�ֵΪ: " << *pos << endl;
	}

}


class find_cus_type {
public:
	string name;
	int age;

	find_cus_type(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

// �Զ������ͺ�������
// ��������������20�Ķ���
class find_cus_type_com {
public:
	bool operator()(const find_cus_type &p) {
		return p.age > 30;
	}
};


// �Զ������Ͳ���
void test_find_if_cus_type() {
	find_cus_type f1("����", 35);
	find_cus_type f2("����", 35);
	find_cus_type f3("�ŷ�", 35);
	find_cus_type f4("����", 25);
	find_cus_type f5("�ܲ�", 45);
	vector<find_cus_type> v1;
	v1.push_back(f1);
	v1.push_back(f2);
	v1.push_back(f3);
	v1.push_back(f4);
	v1.push_back(f5);

	vector<find_cus_type>::iterator pos = find_if(v1.begin(), v1.end(), find_cus_type_com());
	if (pos == v1.end()) {
		cout << "û���ҵ�. " << endl;
	}
	else {
		cout << "Ԫ���ҵ�, name= " << pos->name << ", age = " << pos->age << endl;
	}
}


//int main() {
//	//testInterFind_if();
//	test_find_if_cus_type();
//	system("pause");
//	return 0;
//}