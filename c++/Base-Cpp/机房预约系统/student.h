#pragma once
//#ifndef _STUDENT_H
//#define _STUDENT_H
#include <iostream>
#include <fstream>
#include "identy.h"
#include "globalFile.h"
using namespace std;

class student :public identy {
public:

	student();

	student(string name, string pwd, string id);

	// �����˵�
	virtual void operMenu();

	// ����ԤԼ
	void applyOrder();
	// �鿴�Լ�����
	void showMyOrder();
	// �鿴���ж���
	void showAllOrder();

	// ȡ������
	void cancelOrder();

	// ѧ�����
	string s_id;
};


//#endif // !__STUDENT_H__
