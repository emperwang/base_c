#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &it) {
	for (vector<int>::iterator bg = it.begin(); bg != it.end(); bg++) {
		cout << *bg << " ";
	}
	cout << endl;
}


void testAdd() {
	// Ĭ�Ϲ��캯��
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(10);
	cout << "size = " << v.size() << endl;
	printVector(v);

	// ���乹�캯��
	vector<int> v2(v.begin(), v.end());
	printVector(v2);

	// n �� element ���췽ʽ
	vector<int> v3(10, 20);
	printVector(v3);

	// ��������
	vector<int> v4 = v;
	printVector(v4);

}

// ���Ը�ֵ����
void testAssign() {
	// 1. ��ʼ��һ��vector
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	// = �� ��ֵ
	vector<int> v2 = v1;
	printVector(v2);

	// assign��ֵ
	vector<int>  v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);
	// assign  n��element ��ֵ
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

// vector ��������������
void testCap() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// �ж��Ƿ�Ϊ��
	if (v.empty()) {
		cout << "v ��Ԫ��Ϊ��" << endl;
	}
	else {
		cout << "v. �����ǿ� : " << v.empty() << endl;

		// ��ӡ������Ԫ������
		cout << "v ������Ϊ :" << v.capacity() << endl;
		cout << "v ��Ԫ������ : " << v.size() << endl;
	}


	// �������ô�С
	v.resize(12);
	printVector(v);

	v.resize(15, 100);  // resize�������ԭ���󣬲���2����ָ��������. ��ָ���Ļ�  Ĭ�����0
	printVector(v);

	v.resize(5);
	printVector(v);


}

// vector ���ɾ��
/*
push_back(ele)	// β��
pop_back();		//	βɾ
insert(const_iterator pos, ele);		// �ڵ�����ָ����λ�ò���Ԫ��
insert(const_iterator pos , int count,ele);	// �ڵ�����ָ����λ�ã� ����count��ele
erase(const_iterator pos);		// ɾ��������ָ����λ���ϵ�Ԫ��
erase(const_iterator start, const_iterator end);	// ɾ�������������Ԫ��
clear();		// ����

*/
void testFix() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
	// β������
		v.push_back(i);
	}
	printVector(v);

	// β��ɾ��
	v.pop_back();
	printVector(v);
	// insert ����
	v.insert(v.begin(), 100000);
	printVector(v);

	// insert
	v.insert(v.begin(), 2, 20000);
	printVector(v);


	// erase
	v.erase(v.begin());
	printVector(v);

	// erase
	//v.erase(v.begin(), v.end());
	
	v.clear();
	printVector(v);
}


// vector ������Ԫ�ػ�ȡ
void testGet() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}


	// �����Ż�ȡ������Ԫ��ֵ
	cout << "�����Ż�ȡԪ�� []" << endl;
	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << " ";
	}
	cout << endl;

	// at��ȡԪ��ֵ
	cout << "at ��ȡֵ " << endl;
	for (int k = 0; k < v.size(); k++) {
		cout << v.at(k) << " ";
	}
	cout << endl;

	cout << "��ȡ��һ��Ԫ��: " << v.front() << endl;

	cout << "��ȡ���һ��Ԫ��:" << v.back() << endl;

}

// vector �ռ佻��
void testSwap() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	cout << "����ǰ" << endl;
	printVector(v1);
	printVector(v2);

	v1.swap(v2);
	cout << "������ : " << endl;
	printVector(v1);
	printVector(v2);


}
// �����ռ����;
void swapUse() {
	vector<int> v1;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
	}

	// ��ʱ�������Լ���С
	cout << "cap  :" << v1.capacity() << endl;
	cout << "size :" << v1.size() << endl;

	// �������ô�С��
	// �������ô�С��size��3������������13�򣬴��ںܴ�Ŀռ��˷ѣ�����Ҫ���пռ佻��
	v1.resize(3);

	// �ռ佻��
	vector<int>(v1).swap(v1);
	cout << "cap  :" << v1.capacity() << endl;
	cout << "size :" << v1.size() << endl;

}

// Ԥ���ռ�
void testResover() {

	// ����10������ݣ����Բ��Խ����˼��οռ�����
	vector<int> v1, v2;
	v2.reserve(100000);
	int num = 0, num1 = 0;
	int *p = NULL, *p2 = NULL;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		v2.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;
		}
		if (p2 != &v2[0]) {
			p2 = &v2[0];
			num1++;
		}
	}

	cout << "v1�����ݴ��� : " << num << endl;
	cout << "v2�����ݴ��� :" << num1 << endl;
}


//int main() {
//	//testAdd();
//	//testAssign();
//	//testCap();
//	//testFix();
//	//testGet();
//	//testSwap();
//	//testSwap();
//	//swapUse();
//	testResover();
//	
//	system("pause");
//	return 0;
//}