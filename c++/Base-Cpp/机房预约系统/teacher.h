#ifndef __TEACHER_H__
#define __TEACHER_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "globalFile.h"
#include "identy.h"
using namespace std;
class teacher :public identy {
public:
	teacher();
	teacher(string name, string pwd, string tid);
	virtual void operMenu();

	// �鿴����
	void showAllOrder();

	// ���
	void validOrder();

	// ��ʦ���
	string t_id;
};


#endif // !__TEACHER_H__
