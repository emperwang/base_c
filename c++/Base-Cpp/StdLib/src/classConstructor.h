#ifndef __CLASSCONSTRUCTOR_H__
#define __CLASSCONSTRUCTOR_H__
#include <string>
// ��֤���캯�� ��ʼ����ʽ
class People {
public:
	// ���캯������������
	People();
	~People();

	void showInfo();

	int id;
	std::string name;
	std::string addr;

};

#endif