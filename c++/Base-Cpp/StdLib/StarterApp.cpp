#include <iostream>
#include <string>
#include "globalTemplateFriend.hpp"
#include "classConstructor.h"
#include "People.hpp"
using namespace std;

// 测试类内的友元函数
void test01() {
	Person<string, int>  p("zhangsan", 20l);

	printPerson(p);
}

// 测试类外的友元函数
void test02() {
	Person<string, int> pp("wangwu", 100);
	printPerson2(pp);
}

// 测试people的拷贝函数
void testCopyFun() {
	Peoples p;
	p.name = "wangwu";
	p.printInfo();
	Peoples pw = p;
	pw.printInfo();

	Peoples pd;
	pd.printInfo();
}
//
//int main(int argc, char *argv[]) {
//	//test01();
//	//test02();
//	// People pp;
//	// pp.showInfo();
//	testCopyFun();
//
//	system("pause");
//	return 0;
//}