#include <iostream>
#include <cstdlib>
using namespace std;
// 声明函数
template<class T>
T add(T a, T b);

// 非类型参数的模板类型
template <class type, int size>
void showArray(type(&array)[size]) {
	int i;
	cout << "template 非类型模板函数" << endl;
	cout << "array_size " << size << endl;
	for (i = 0; i < size; i++) {
		cout << "array[" << i << "] = " << array[i] << " ";
	}
	cout << endl;
}

// 引用函数
int ref_func(int &a, int &b) {
	int temp = a;
	a -= b;
	b += a;
	return a;
}

// 指针函数为参数的函数
void my_print(char *str) {
	cout << "myprint: " << (str) << endl;
}

void point_function(void (*pp)(char *), char *str) {
	// 调用指针指向的函数
	pp(str);
}

// 指针函数数组
void funa() {
	cout << "funa running" << endl;
}

void funb() {
	cout << "funb running" << endl;
}

void func() {
	cout << "func running" << endl;
}
// 函数指针数组  定义
void(*pArr[])() = {funa,funb,func};





int main() {
	cout << "基本函数调用" << endl;
	int res = add(100, 200);
	cout << res << endl;

	cout << endl;
	cout << "非类型参数的模板函数" << endl;
	int a[] = { 1,2,3,4,5,6 };
	showArray(a);

	cout << endl;
	cout << "引用函数调用" << endl;
	int refa = 30;
	int refb = 20;
	cout << "origin refa = " << refa << ", origin refb = " << refb << endl;
	ref_func(refa, refb);
	cout << "after func: refa" << refa << ",  after func: refbb = " << refb << endl;

	cout << endl;
	cout << "函数指针 为参数的函数 调用" << endl;
	char *stt = "this is pointer function working...";
	point_function(my_print, stt);

	cout << endl;
	cout << "函数指针数组调用" << endl;
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