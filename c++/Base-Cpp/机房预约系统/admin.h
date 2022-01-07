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

	// 显示管理员菜单界面
	virtual void operMenu();
	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看机房信息
	void showComputer();

	// 清空预约记录
	void cleanOrder();

	// 添加管理员
	void addAdmin();

	// 加载学生以及老师的数据
	void loadRecords();

	// 加载机房信息
	void loadComputerInfo();

	// 学生添加
	void addStudent();
	// 老师添加
	void addTeacher();

	bool checkRepeat(int role, string id);

	// 打印 老师 或学生信息
	void printTeacher();
	void printStudent();

	// 保存老师 以及 学生的表中数据
	vector<student> studs;
	vector<teacher> teachs;
	// 保存机房信息
	vector<computerRoom> coms;
};

//#endif // !1
