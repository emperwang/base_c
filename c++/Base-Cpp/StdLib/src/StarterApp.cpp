#include <iostream>
#include <string>
#include "globalTemplateFriend.hpp"
#include "classConstructor.h"
#include "People.hpp"
using namespace std;

// �������ڵ���Ԫ����
void test01() {
	Person<string, int>  p("zhangsan", 20l);

	printPerson(p);
}

// �����������Ԫ����
void test02() {
	Person<string, int> pp("wangwu", 100);
	printPerson2(pp);
}

// ����people�Ŀ�������
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