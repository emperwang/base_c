#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "admin.h"
using namespace std;

// ��ʾѧ���Ĳ˵�
void showStudentMenu(identy *ident);
// ��ʾ��ʦ�Ĳ˵�
void showTeacerMenu(identy *ident);
//��ʾ����Ա�Ĳ˵�
void showAdminMenu(identy* &ident);
// ���˵�����ʾ
void showMainMenu();
// �û���¼ file: Ҫ�������ļ�	role ��¼�Ľ�ɫ
void rolelogin(string file,int role);


int main() {
	int select = 0;
	while (true) {
		showMainMenu();
		cin >> select;
		switch (select) {
		case studentRole:			// ѧ����¼
			rolelogin(STUDENT_FILE, studentRole);
			break;
		case teacherRole:			// ��ʦ��¼
			rolelogin(TEACHER_FILE, teacherRole);
			break;
		case adminRole:			// ����Ա
			rolelogin(ADMIN_FILE, adminRole);
			break;
		case logout:			// �˳�ϵͳ
			cout << "ллʹ�û���ԤԼϵͳ. ��ӭ�´ι���" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�������������������." << endl;
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
			cout << "������Ҫ��¼���û���: " << endl;
			cin >> inputname;
			cout << "������Ҫ��¼���û�������" << endl;
			cin >> inputpwd;
			cout << "������ѧ����� :" << endl;
			cin >> inputsid;
			while (ifs >> readname && ifs >> readpwd && ifs >> readsid) {
				if (readname == inputname && readpwd == inputpwd && readsid == inputsid) {
					cout << "ѧ�� " << inputname << " ��¼�ɹ�." << endl;
					ifs.close();
					system("pause");
					system("cls");
					identy * ident = new student(readname, readpwd, readsid);
					showStudentMenu(ident);
					break;
				}
			}
			cout << "�˻��������.." << endl;
			break;
		}
		case teacherRole: {
			string inputname;
			string inputpwd;
			string inputtid;
			string readname;
			string readpwd;
			string readtid;
			cout << "������Ҫ��¼���û���: " << endl;
			cin >> inputname;
			cout << "������Ҫ��¼���û�������" << endl;
			cin >> inputpwd;
			cout << "������Ҫ��¼����ʦ���" << endl;
			cin >> inputtid;
			while (ifs >> readname && ifs >> readpwd && ifs >> readtid) {
				if (readname == inputname && readpwd == inputpwd && readtid == inputtid) {
					cout << "��ʦ " << inputname << " ��¼�ɹ�." << endl;
					ifs.close();
					system("pause");
					system("cls");
					identy *ident = new teacher(readname, readpwd, readtid);
					showTeacerMenu(ident);
					break;
				}
			}
			cout << "�˻��������.." << endl;
			break;
		}
		case adminRole:
			{
				string name;	// ��ȡ�û������� �û��� 
				string pwd;		// �û����������
				string readName;
				string readpwd;
				cout << "������Ҫ��¼���û���: " << endl;
				cin >> name;
				cout << "������Ҫ��¼���û�������" << endl;
				cin >> pwd;
				while (ifs >> readName && ifs >> readpwd) {
					if (readName == name && readpwd == pwd) {
						cout << "����Ա: "<<readName << " ��¼�ɹ�" << endl;
						ifs.close();
						identy *ident = new admin(name, pwd);
						system("pause");
						system("cls");
						showAdminMenu(ident);
						break;
					}
				}
				cout << "�˻��������.." << endl;
				break;
			}
		default:
			cout << "�����ڵ��û���ɫ." << endl;
			system("pause");
			return;
		}
	}
	else {
		cout << file << "  ���ݿ��ļ�������.��������." << endl;
	}
	ifs.close();

}

// ��ʾѧ���Ĳ˵�
void showStudentMenu(identy *ident) {
	student * stu = (student *)ident;
	int sel = 0;
	cin.clear();
	while (true) {
		stu->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:		// ����ԤԼ
			stu->applyOrder();
			break;
		case 2:		// �鿴�ҵ�ԤԼ
			stu->showMyOrder();
			break;
		case 3:		// �鿴����ԤԼ
			stu->showAllOrder();
			break;
		case 4:		// ȡ��ԤԼ
			stu->cancelOrder();
			break;
		case 5:		// ע����¼
		{
			cout << "ѧ��: " << stu->m_name << " �˳���¼�� ��ӭ�´ι���" << endl;
			delete stu;
			system("pause");
			system("cls");
			return;
		}
		default:
		{
			cout << "��������, ����������." << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}
}
// ��ʾ��ʦ�Ĳ˵�
void showTeacerMenu(identy *ident) {
	teacher *tea = (teacher *)ident;
	int sel = 0;
	cin.clear();
	while (true) {
		tea->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:		// �鿴����ԤԼ
			tea->showAllOrder();
			break;
		case 2:		// ���ԤԼ
			tea->validOrder();
			break;
		case 3:		// ע����¼
		{
			cout << "��ʦ: " << tea->m_name << " �˳���¼�� ��ӭ�´ι���" << endl;
			delete tea;
			system("pause");
			system("cls");
			return;
			break;
		}
		default:
			cout << "��������, ����������." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void showAdminMenu(identy* &ident) {
	// ����ǿת
	admin *ad = (admin *)ident;
	int sel = 0;
	cin.clear();
	//cin.ignore();// ���һ���ַ�
	//cin.ignore(numeric_limits<std::streamsize>::max());	// �������������������
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // ����������ĵ�ǰ��
	while (true) {
		ad->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:			// ����û�
			ad->addPerson();
			break;
		case 2:			// �鿴�˺�
			ad->showPerson();
			break;
		case 3:			// �鿴����
			ad->showComputer();
			break;
		case 4:			// ���ԤԼ
			ad->cleanOrder();
			break;
		case 5:			// ע����¼
			cout << "����Ա :" << ad->m_name << " �˳���¼." << endl;
			delete ad;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������, ����������." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void showMainMenu() {
	cout << "****** ����ԤԼϵͳ *******" << endl;
	cout << "---------------------------\n";
	cout << "|1.ѧ������		|\n";
	cout << "|2.��ʦ			|\n";
	cout << "|3.����Ա		|\n";
	cout << "|0.�˳�ϵͳ		|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ��¼���û�:" << endl;
}