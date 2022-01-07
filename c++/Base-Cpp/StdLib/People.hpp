#ifndef __PEOPLE_H__
#define __PEOPLE_H__

#include <string>
#include <iostream>
using namespace std;
class Peoples {
public:
	string name;
	int age;

	// 拷贝函数
	Peoples(const Peoples &p) {
		this->name = p.name;
		this->age = p.age;
	}

	// 构造函数  析构函数
	Peoples():name("zhangsan"),age(10)
	{}
	~Peoples(){}


	void printInfo() {
		cout << "name : " << this->name
			<< "\t age = :" << this->age << endl;
	}
};


#endif