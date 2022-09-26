#ifndef __IDENTY_H__
#define __IDENTY_H__
#include <iostream>
#include <string>
using namespace std;

class identy {
public:
	// 操作菜单的虚函数
	virtual void operMenu() = 0;

	// 用户名 和 密码
	string m_name;
	string m_pwd;
};




#endif // !__IDENTY_H__
