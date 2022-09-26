#include <iostream>
using namespace std;
#include <string>
/*
函数对象(仿函数):
函数对象在使用时, 可以像普通函数那样调用, 可以有参数,可以有返回值
函数对戏那个超出普通函数的概念, 函数对象可以有自己的状态
函数对象可以作为参数传递
*/

//函数对象在使用时, 可以像普通函数那样调用, 可以有参数,可以有返回值
class MaddFunc {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

void testPredone() {
	MaddFunc add;
	int ret = add(100, 200);
	cout << "add result : " << ret << endl;
}

// 函数对戏那个超出普通函数的概念, 函数对象可以有自己的状态
class Mprint {
public:
	Mprint() {
		this->count = 0;
	}

	void operator()(string text) {
		cout << text << endl;
		this->count++;
	}
	// 记录函数 调用多少次
	int count;
};

//函数对象可以作为参数传递
void doPrint(Mprint &p, string text) {
	p(text);
}

void testMPrint() {
	Mprint print;
	print("hello");
	print("hello");
	print("hello");
	print("hello");
	cout << "call times: " << print.count << endl;

	doPrint(print,("this is do print running"));
}


//int main() {
//	//testPredone();
//	testMPrint();
//
//	system("pause");
//	return 0;
//}