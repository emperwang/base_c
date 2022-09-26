#include <iostream>
#include <stdio.h>
using namespace std;

int main01() {
	int a = 4;
	float b = 4.0;
	double c = 3.1415926;

	int &d = a;
	int *p = &a;

	cout << "int = " << sizeof(a) << endl;
	cout << "float = " << sizeof(b) << endl;
	cout << "double = " << sizeof(c) << endl;

	cout << "引用d = " << d << endl;

	cout << "指针p值= " << *p << endl;

	int one = 100;
	double two = 200.0056;
	printf("original result = %f \n", one + two);
	printf("result = %d \n", one + static_cast<int>(two));
	
	cout << "-------------------------------------------" << endl;
	// 指针引用的使用
	int arri[] = { 1,2,3,4,5,6,7,8 };
	int arr2[] = { 9,8,7,6,5,4 };
	int *p1 = arri;
	int *p2 = arr2;
	int  i = 0;
	for (; i < sizeof(arri) / sizeof(arri[0]); i++) {
		cout << *(p1 + i) ;
	}
	cout << endl;
	// 指针引用的声明  赋值
	int *iref1 = p1;
	int *iref2 = p2;
	cout << "引用打印" << endl;
	for (i = 0; i < sizeof(arri) / sizeof(arri[0]); i++) {
		cout << *(iref1 + i) << endl;
	}

	float ff = 0.5;
	float fg = 10.5;
	// 常量指针
	const float *f1 = &ff;
	f1 = &fg;	// 常量指针可以修改指向，但是不能修改值
	// *f1 = 100;	// 错误  值不可修改
	cout << *f1 << endl;

	// 指针常量
	float* const f2 = &ff;
	//f2 = &f2;	// 指针常量 的 指针指向不可修改
	*f2 = 100;	// 指针的 值可以修改；
	cout << *f2 << endl;

	system("pause");
	return 0;
}