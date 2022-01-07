#include <iostream>
#include <string>
#include "classConstructor.h"
using namespace std;

People::People():id(1),name("zhangsan"),addr("beijing")
{}

People::~People() {}

void People::showInfo() {
	cout << "id = " << this->id
		<< "\t name= " << this->name
		<< "\t addr = " << this->addr << endl;
}