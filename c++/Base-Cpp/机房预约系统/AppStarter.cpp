#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "admin.h"
using namespace std;

// 显示学生的菜单
void showStudentMenu(identy *ident);
// 显示老师的菜单
void showTeacerMenu(identy *ident);
//显示管理员的菜单
void showAdminMenu(identy* &ident);
// 主菜单的显示
void showMainMenu();
// 用户登录 file: 要操作的文件	role 登录的角色
void rolelogin(string file,int role);


int main() {
	int select = 0;
	while (true) {
		showMainMenu();
		cin >> select;
		switch (select) {
		case studentRole:			// 学生登录
			rolelogin(STUDENT_FILE, studentRole);
			break;
		case teacherRole:			// 老师登录
			rolelogin(TEACHER_FILE, teacherRole);
			break;
		case adminRole:			// 管理员
			rolelogin(ADMIN_FILE, adminRole);
			break;
		case logout:			// 退出系统
			cout << "谢谢使用机房预约系统. 欢迎下次光临" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入的有误，请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	


	system("pause");
	return 0;
}

void rolelogin(string file, int role) {
	ifstream ifs;
	ifs.open(file);

	if (ifs.is_open()) {
		switch (role) {
		case studentRole: {
			string inputname;
			string inputpwd;
			string inputsid;
			string readname;
			string readpwd;
			string readsid;
			cout << "请输入要登录的用户名: " << endl;
			cin >> inputname;
			cout << "请输入要登录的用户的密码" << endl;
			cin >> inputpwd;
			cout << "请输入学生编号 :" << endl;
			cin >> inputsid;
			while (ifs >> readname && ifs >> readpwd && ifs >> readsid) {
				if (readname == inputname && readpwd == inputpwd && readsid == inputsid) {
					cout << "学生 " << inputname << " 登录成功." << endl;
					ifs.close();
					system("pause");
					system("cls");
					identy * ident = new student(readname, readpwd, readsid);
					showStudentMenu(ident);
					break;
				}
			}
			cout << "账户密码错误.." << endl;
			break;
		}
		case teacherRole: {
			string inputname;
			string inputpwd;
			string inputtid;
			string readname;
			string readpwd;
			string readtid;
			cout << "请输入要登录的用户名: " << endl;
			cin >> inputname;
			cout << "请输入要登录的用户的密码" << endl;
			cin >> inputpwd;
			cout << "请输入要登录的老师编号" << endl;
			cin >> inputtid;
			while (ifs >> readname && ifs >> readpwd && ifs >> readtid) {
				if (readname == inputname && readpwd == inputpwd && readtid == inputtid) {
					cout << "老师 " << inputname << " 登录成功." << endl;
					ifs.close();
					system("pause");
					system("cls");
					identy *ident = new teacher(readname, readpwd, readtid);
					showTeacerMenu(ident);
					break;
				}
			}
			cout << "账户密码错误.." << endl;
			break;
		}
		case adminRole:
			{
				string name;	// 读取用户的输入 用户名 
				string pwd;		// 用户输入的密码
				string readName;
				string readpwd;
				cout << "请输入要登录的用户名: " << endl;
				cin >> name;
				cout << "请输入要登录的用户的密码" << endl;
				cin >> pwd;
				while (ifs >> readName && ifs >> readpwd) {
					if (readName == name && readpwd == pwd) {
						cout << "管理员: "<<readName << " 登录成功" << endl;
						ifs.close();
						identy *ident = new admin(name, pwd);
						system("pause");
						system("cls");
						showAdminMenu(ident);
						break;
					}
				}
				cout << "账户密码错误.." << endl;
				break;
			}
		default:
			cout << "不存在的用户角色." << endl;
			system("pause");
			return;
		}
	}
	else {
		cout << file << "  数据库文件不存在.请先配置." << endl;
	}
	ifs.close();

}

// 显示学生的菜单
void showStudentMenu(identy *ident) {
	student * stu = (student *)ident;
	int sel = 0;
	cin.clear();
	while (true) {
		stu->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:		// 申请预约
			stu->applyOrder();
			break;
		case 2:		// 查看我的预约
			stu->showMyOrder();
			break;
		case 3:		// 查看所有预约
			stu->showAllOrder();
			break;
		case 4:		// 取消预约
			stu->cancelOrder();
			break;
		case 5:		// 注销登录
		{
			cout << "学生: " << stu->m_name << " 退出登录。 欢迎下次光临" << endl;
			delete stu;
			system("pause");
			system("cls");
			return;
		}
		default:
		{
			cout << "输入有误, 请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}
// 显示老师的菜单
void showTeacerMenu(identy *ident) {
	teacher *tea = (teacher *)ident;
	int sel = 0;
	cin.clear();
	while (true) {
		tea->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:		// 查看所有预约
			tea->showAllOrder();
			break;
		case 2:		// 审核预约
			tea->validOrder();
			break;
		case 3:		// 注销登录
		{
			cout << "老师: " << tea->m_name << " 退出登录。 欢迎下次光临" << endl;
			delete tea;
			system("pause");
			system("cls");
			return;
			break;
		}
		default:
			cout << "输入有误, 请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void showAdminMenu(identy* &ident) {
	// 进行强转
	admin *ad = (admin *)ident;
	int sel = 0;
	cin.clear();
	//cin.ignore();// 清除一个字符
	//cin.ignore(numeric_limits<std::streamsize>::max());	// 清除缓冲区中所有内容
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区的当前行
	while (true) {
		ad->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:			// 添加用户
			ad->addPerson();
			break;
		case 2:			// 查看账号
			ad->showPerson();
			break;
		case 3:			// 查看机房
			ad->showComputer();
			break;
		case 4:			// 清空预约
			ad->cleanOrder();
			break;
		case 5:			// 注销登录
			cout << "管理员 :" << ad->m_name << " 退出登录." << endl;
			delete ad;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误, 请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void showMainMenu() {
	cout << "****** 机房预约系统 *******" << endl;
	cout << "---------------------------\n";
	cout << "|1.学生代表		|\n";
	cout << "|2.老师			|\n";
	cout << "|3.管理员		|\n";
	cout << "|0.退出系统		|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要登录的用户:" << endl;
}