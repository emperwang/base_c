#ifndef __PEOPLE_H__
#define __PEOPLE_H__

#include <string>
#include <iostream>
using namespace std;
class Peoples {
public:
	string name;
	int age;

	// ��������
	Peoples(const Peoples &p) {
		this->name = p.name;
		this->age = p.age;
	}

	// ���캯��  ��������
	Peoples():name("zhangsan"),age(10)
	{}
	~Peoples(){}


	void printInfo() {
		cout << "name : " << this->name
			<< "\t age = :" << this->age << endl;
	}
};


#endif