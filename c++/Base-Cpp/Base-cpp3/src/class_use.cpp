#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Persion {
private:
	int age;
	char *name;

public:
	// 构造函数
	Persion();

	// 设置 以及 获取年龄 和名字
	void setAge(int age) {
		this->age = age;
	}
	void setName(char *name) {
		this->name = name;
	}

	int getAge() {
		return this->age;
	}

	char *getName() {
		return this->name;
	}

	void printInfo();


	// 析构函数
	~Persion() {
		cout << "析构函数" << endl;
	}
};

// 类外定义构造函数
Persion::Persion() {
	cout << "构造函数" << endl;
	// this指针的使用
	this->age = 0;
	this->name = NULL;
}

void Persion::printInfo() {
	if (this->name == NULL) {
		cout << "age = " << this->age << ", name : NULL "<< endl;
	}else{
		cout << "age = " << this->age << ",name : " << this->name << endl;
	}
	
}

int main() {
	// 类对象的定义
	Persion p1;
	p1.printInfo();
	p1.setAge(10);
	char tt[] = "Mike";
	p1.setName(tt);
	//p1.setName(&tt[0]);
	p1.printInfo();


	system("pause");
	return 0;
}