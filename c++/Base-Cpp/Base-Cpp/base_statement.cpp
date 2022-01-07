#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int a = 4;
	float b = 4.0;
	double c = 3.1415926;

	int &d = a;
	int *p = &a;

	cout << "int = " << sizeof(a) << endl;
	cout << "float = " << sizeof(b) << endl;
	cout << "double = " << sizeof(c) << endl;

	cout << "����d = " << d << endl;

	cout << "ָ��pֵ= " << *p << endl;

	int one = 100;
	double two = 200.0056;
	printf("original result = %f \n", one + two);
	printf("result = %d \n", one + static_cast<int>(two));
	
	cout << "-------------------------------------------" << endl;
	// ָ�����õ�ʹ��
	int arri[] = { 1,2,3,4,5,6,7,8 };
	int arr2[] = { 9,8,7,6,5,4 };
	int *p1 = arri;
	int *p2 = arr2;
	int  i = 0;
	for (; i < sizeof(arri) / sizeof(arri[0]); i++) {
		cout << *(p1 + i) ;
	}
	cout << endl;
	// ָ�����õ�����  ��ֵ
	int *iref1 = p1;
	int *iref2 = p2;
	cout << "���ô�ӡ" << endl;
	for (i = 0; i < sizeof(arri) / sizeof(arri[0]); i++) {
		cout << *(iref1 + i) << endl;
	}

	float ff = 0.5;
	float fg = 10.5;
	// ����ָ��
	const float *f1 = &ff;
	f1 = &fg;	// ����ָ������޸�ָ�򣬵��ǲ����޸�ֵ
	// *f1 = 100;	// ����  ֵ�����޸�
	cout << *f1 << endl;

	// ָ�볣��
	float* const f2 = &ff;
	//f2 = &f2;	// ָ�볣�� �� ָ��ָ�򲻿��޸�
	*f2 = 100;	// ָ��� ֵ�����޸ģ�
	cout << *f2 << endl;

	system("pause");
	return 0;
}