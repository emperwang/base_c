#include "admin.h"
#include "comOrder.h"
admin::admin() {
	this->loadRecords();
	this->loadComputerInfo();
}
admin::admin(string name, string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->loadRecords();
	this->loadComputerInfo();
}

// ��ʾ����Ա�˵�����
void admin::operMenu() {
	cout << "��ӭ����Ա: "<< this->m_name <<" ��¼." << endl;
	cout << "---------------------------\n";
	cout << "|1.����˺�		|\n";
	cout << "|2.�鿴�˺�		|\n";
	cout << "|3.�鿴����		|\n";
	cout << "|4.���ԤԼ		|\n";
	cout << "|5.ע����¼		|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ���еĲ���:" << endl;
}
void admin::addStudent() {
	string name;
	string pwd;
	string sid;
	cout << "������ѧ�����:" << endl;
	cin >> sid;
	while (this->checkRepeat(studentRole, sid)) {
		cout << "ѧ����� " << sid << " �Ѿ����ڣ�����������." << endl;
		cin >> sid;
	}
	cout << "������ѧ������ :" << endl;
	cin >> name;
	cout << "������ѧ������: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(STUDENT_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;
	ofs.close();

	// ����Ӻ����¼�������
	this->loadRecords();
}

void admin::addTeacher() {
	string name;
	string pwd;
	string sid;
	cout << "��������ʦ���:" << endl;
	cin >> sid;
	while (this->checkRepeat(teacherRole, sid)) {
		cout << "��ʦ��� " << sid << " �Ѿ����ڣ�����������." << endl;
		cin >> sid;
	}
	cout << "��������ʦ���� :" << endl;
	cin >> name;
	cout << "��������ʦ����: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(TEACHER_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;
	ofs.close();

	this->loadRecords();
}
// ����˺�
void admin::addPerson() {
	cout << "����û�" << endl;
	ofstream ofs;
	
	int sel = 0;
	while (true){
		cout << "������Ҫ��ӵ��û��Ľ�ɫ���� : " << endl;
		cout << "1.ѧ��" << endl;
		cout << "2.��ʦ" << endl;
		cout << "3.����Ա" << endl;
		cin >> sel;
		switch (sel) {
		case 1:	// ͬѧ
		{	
			addStudent();
			return;
		}
		case 2:	// ��ʦ
		{
			addTeacher();
			return;
		}
		case 3:	// ����Ա
		{
			addAdmin();
			return;
		}
		default:
			cout << "��������Ͳ���ȷ������������." << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}
bool admin::checkRepeat(int role, string id) {
	if (role == studentRole) {
		for (vector<student>::iterator it = this->studs.begin(); it != this->studs.end(); it++) {
			if (id == it->s_id) {	//atoi(sid.c_str)  // string ת��Ϊ int
				return true;
			}
		}
		return false;
	}
	else if (role == teacherRole) {
		for (vector<teacher>::iterator it = this->teachs.begin(); it != this->teachs.end(); it++) {
			if (id == it->t_id) {	//atoi(sid.c_str)  // string ת��Ϊ int
				return true;
			}
		}
		return false;
	}
}
// �鿴�˺�
void admin::showPerson() {
	cout << "չʾ�û�" << endl;
	int sel = 0;
	while (true) {
		cout << "��������չʾ�Ľ�ɫ:" << endl;
		cout << "1.��ʦ" << endl;
		cout << "2.ѧ��" << endl;
		cin >> sel;
		if (sel == 1) {
			this->printTeacher();
			break;
		}
		else if (sel == 2) {
			this->printStudent();
			break;
		}
		else {
			cout << "������������������." << endl;
		}
	}
	system("pause");
	system("cls");
}

void printComputer(computerRoom com) {
	cout << "������ : " << com.room_id << "��������:" << com.room_cap << endl;
}

void admin::loadComputerInfo() {
	// ���ػ�����Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_fILE, ios::in);
	if (ifs.is_open()) {
		string id;
		string cap;
		while (ifs >> id && ifs >> cap) {
			this->coms.push_back(computerRoom(atoi(id.c_str()), atoi(cap.c_str())));
		}
	}
	else {
		cout << "���޿��õĻ���..." << endl;
	}
	ifs.close();
}

// �鿴������Ϣ
void admin::showComputer() {
	cout << "չʾ������Ϣ" << endl;
	// չʾ������Ϣ
	for_each(this->coms.begin(), this->coms.end(), printComputer);
}

// ���ԤԼ��¼
void admin::cleanOrder() {
	cout << "���ԤԼ��Ϣ." << endl;
	cout << "��պ����ݽ���ʧ����ȷ�������Ҫ���ԤԼ��Ϣ��" << endl;
	int sel = -1;
	while (true) {
		cout << "0.ȡ��" << endl;
		cout << "1.ȷ��" << endl;
		cin >> sel;
		if (sel == 0 || sel == 1) {
			break;
		}
		else {
			cout << "������������������." << endl;
			system("pause");
			system("cls");
		}
	}
	if (sel == 1) {
		order od;
		od.ods.clear();
		od.updateAllOrder();
		cout << "������" << endl;
		system("pause");
		system("cls");
	}

}


void printStu(student &st) {
	cout << "ѧ������:" << st.m_name << "\t pwd:***" << "\tѧ��ID:" << st.s_id << endl;
}

void admin::printStudent() {
	for_each(this->studs.begin(), this->studs.end(), printStu);
}

void printTea(teacher &st) {
	cout << "��ʦ����:" << st.m_name << "\t pwd: ***" << "\t��ʦID:" << st.t_id << endl;
}

void admin::printTeacher() {
	for_each(this->teachs.begin(), this->teachs.end(), printTea);
}

void admin::loadRecords() {
	this->studs.clear();
	this->teachs.clear();
	ifstream ifs,ifs1;
	ifs.open(STUDENT_FILE, ios::in);
	if (ifs.is_open()) {
		string name;
		string pwd;
		string sid;
		while (ifs >> name && ifs >> pwd && ifs >> sid) {
			this->studs.push_back(student(name, pwd, sid));
		}
	}
	else {
	//	cout << "ѧ�����ݲ�����." << endl;
	}
	ifs.close();
	ifs1.open(TEACHER_FILE, ios::in);
	if (ifs1.is_open()) {
		string name;
		string pwd;
		string sid;
		while (ifs1 >> name && ifs1 >> pwd && ifs1 >> sid) {
			this->teachs.push_back(teacher(name, pwd, sid));
		}
	}
	else {
		//cout << "��ʦ���ݲ�����." << endl;
	}
	ifs1.close();
}



void admin::addAdmin() {
	string name;
	string pwd;
	string sid;
	cout << "���������Ա�û��� :" << endl;
	cin >> name;
	cout << "���������Ա����: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(ADMIN_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << endl;
	ofs.close();
}