#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Persion {
private:
	int age;
	char *name;

public:
	// ���캯��
	Persion();

	// ���� �Լ� ��ȡ���� ������
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


	// ��������
	~Persion() {
		cout << "��������" << endl;
	}
};

// ���ⶨ�幹�캯��
Persion::Persion() {
	cout << "���캯��" << endl;
	// thisָ���ʹ��
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
	// �����Ķ���
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