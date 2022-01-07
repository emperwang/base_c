#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
���ò����㷨:
find				// ����Ԫ��
find_if				// ����������Ԫ��
adjacent_find		// �ҵ������ظ�Ԫ��
binary_search		// ���ֲ���
count				// ͳ��Ԫ�ظ���
count_if			// ������ͳ��Ԫ�ظ���
*/

/*
find(iterator beg, iterator end, value)
��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
beg		��ʼ������
end		����������
value	���ҵ�Ԫ��
*/

// find������������

void testInternalType() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 50);
	if (pos == v.end()){
		cout << "��������û���ҵ�Ԫ��" << endl;
	}
	else {
		cout << "�������в��ҵ�Ԫ�� :" << *pos << endl;
	}

}

class cusComType {
public:
	string name;
	int age;
	// ʹ��find����ʱ, ��Ҫ����==����,��Ȼfind��֪������Ƕ��Զ��������бȽ�
	bool operator==(const cusComType &t) {
		if (this->name == t.name && this->age == t.age) {
			return true;
		}
		else {
			return false;
		}
	}

	cusComType(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

// find�����Զ�������
void testFindCusType() {
	vector<cusComType> v;
	cusComType c1("zhangsan", 30);
	cusComType c2("wnagwu", 50);
	cusComType c3("zhaoliu", 60);
	cusComType c4("zhouqi", 70);
	cusComType c5("lisi", 40);
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(c3);
	v.push_back(c4);
	v.push_back(c5);

	vector<cusComType>::iterator pos = find(v.begin(), v.end(), c2);
	if (pos == v.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "���ҵ�Ԫ��, name = " << pos->name << ", age = " << pos->age << endl;
	}
}


//int main() {
//	// testInternalType();
//	testFindCusType();
//	system("pause");
//	return 0;
//}