#ifndef __IDENTY_H__
#define __IDENTY_H__
#include <iostream>
#include <string>
using namespace std;

class identy {
public:
	// �����˵����麯��
	virtual void operMenu() = 0;

	// �û��� �� ����
	string m_name;
	string m_pwd;
};




#endif // !__IDENTY_H__
