#pragma once
//#ifndef __ADMIN_H__
//#define __ADMIN_H__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "identy.h"
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "computer.h"
using namespace std;
class admin :public identy {
public:
	admin();
	admin(string name,string pwd);

	// ��ʾ����Ա�˵�����
	virtual void operMenu();
	// ����˺�
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴������Ϣ
	void showComputer();

	// ���ԤԼ��¼
	void cleanOrder();

	// ��ӹ���Ա
	void addAdmin();

	// ����ѧ���Լ���ʦ������
	void loadRecords();

	// ���ػ�����Ϣ
	void loadComputerInfo();

	// ѧ�����
	void addStudent();
	// ��ʦ���
	void addTeacher();

	bool checkRepeat(int role, string id);

	// ��ӡ ��ʦ ��ѧ����Ϣ
	void printTeacher();
	void printStudent();

	// ������ʦ �Լ� ѧ���ı�������
	vector<student> studs;
	vector<teacher> teachs;
	// ���������Ϣ
	vector<computerRoom> coms;
};

//#endif // !1
