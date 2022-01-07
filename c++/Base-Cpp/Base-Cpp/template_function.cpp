#include <iostream>
#include <cstdlib>
using namespace std;
// ��������
template<class T>
T add(T a, T b);

// �����Ͳ�����ģ������
template <class type, int size>
void showArray(type(&array)[size]) {
	int i;
	cout << "template ������ģ�庯��" << endl;
	cout << "array_size " << size << endl;
	for (i = 0; i < size; i++) {
		cout << "array[" << i << "] = " << array[i] << " ";
	}
	cout << endl;
}

// ���ú���
int ref_func(int &a, int &b) {
	int temp = a;
	a -= b;
	b += a;
	return a;
}

// ָ�뺯��Ϊ�����ĺ���
void my_print(char *str) {
	cout << "myprint: " << (str) << endl;
}

void point_function(void (*pp)(char *), char *str) {
	// ����ָ��ָ��ĺ���
	pp(str);
}

// ָ�뺯������
void funa() {
	cout << "funa running" << endl;
}

void funb() {
	cout << "funb running" << endl;
}

void func() {
	cout << "func running" << endl;
}
// ����ָ������  ����
void(*pArr[])() = {funa,funb,func};





int main() {
	cout << "������������" << endl;
	int res = add(100, 200);
	cout << res << endl;

	cout << endl;
	cout << "�����Ͳ�����ģ�庯��" << endl;
	int a[] = { 1,2,3,4,5,6 };
	showArray(a);

	cout << endl;
	cout << "���ú�������" << endl;
	int refa = 30;
	int refb = 20;
	cout << "origin refa = " << refa << ", origin refb = " << refb << endl;
	ref_func(refa, refb);
	cout << "after func: refa" << refa << ",  after func: refbb = " << refb << endl;

	cout << endl;
	cout << "����ָ�� Ϊ�����ĺ��� ����" << endl;
	char *stt = "this is pointer function working...";
	point_function(my_print, stt);

	cout << endl;
	cout << "����ָ���������" << endl;
	int i = 0;
	for (; i < sizeof(pArr)/sizeof(pArr[0]); i++) {
		pArr[i]();
	}


	system("pause");
	return 0;
}

template<class T>
T add(T a, T b) {

	return a + b;
}