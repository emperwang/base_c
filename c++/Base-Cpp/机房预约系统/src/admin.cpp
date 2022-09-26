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

// 显示管理员菜单界面
void admin::operMenu() {
	cout << "欢迎管理员: "<< this->m_name <<" 登录." << endl;
	cout << "---------------------------\n";
	cout << "|1.添加账号		|\n";
	cout << "|2.查看账号		|\n";
	cout << "|3.查看机房		|\n";
	cout << "|4.清空预约		|\n";
	cout << "|5.注销登录		|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要进行的操作:" << endl;
}
void admin::addStudent() {
	string name;
	string pwd;
	string sid;
	cout << "请输入学生编号:" << endl;
	cin >> sid;
	while (this->checkRepeat(studentRole, sid)) {
		cout << "学生编号 " << sid << " 已经存在，请重新输入." << endl;
		cin >> sid;
	}
	cout << "请输入学生姓名 :" << endl;
	cin >> name;
	cout << "请输入学生密码: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(STUDENT_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;
	ofs.close();

	// 新添加后，重新加载数据
	this->loadRecords();
}

void admin::addTeacher() {
	string name;
	string pwd;
	string sid;
	cout << "请输入老师编号:" << endl;
	cin >> sid;
	while (this->checkRepeat(teacherRole, sid)) {
		cout << "老师编号 " << sid << " 已经存在，请重新输入." << endl;
		cin >> sid;
	}
	cout << "请输入老师姓名 :" << endl;
	cin >> name;
	cout << "请输入老师密码: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(TEACHER_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;
	ofs.close();

	this->loadRecords();
}
// 添加账号
void admin::addPerson() {
	cout << "添加用户" << endl;
	ofstream ofs;
	
	int sel = 0;
	while (true){
		cout << "请输入要添加的用户的角色类型 : " << endl;
		cout << "1.学生" << endl;
		cout << "2.老师" << endl;
		cout << "3.管理员" << endl;
		cin >> sel;
		switch (sel) {
		case 1:	// 同学
		{	
			addStudent();
			return;
		}
		case 2:	// 老师
		{
			addTeacher();
			return;
		}
		case 3:	// 管理员
		{
			addAdmin();
			return;
		}
		default:
			cout << "输入的类型不正确，请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}
bool admin::checkRepeat(int role, string id) {
	if (role == studentRole) {
		for (vector<student>::iterator it = this->studs.begin(); it != this->studs.end(); it++) {
			if (id == it->s_id) {	//atoi(sid.c_str)  // string 转换为 int
				return true;
			}
		}
		return false;
	}
	else if (role == teacherRole) {
		for (vector<teacher>::iterator it = this->teachs.begin(); it != this->teachs.end(); it++) {
			if (id == it->t_id) {	//atoi(sid.c_str)  // string 转换为 int
				return true;
			}
		}
		return false;
	}
}
// 查看账号
void admin::showPerson() {
	cout << "展示用户" << endl;
	int sel = 0;
	while (true) {
		cout << "输入你想展示的角色:" << endl;
		cout << "1.老师" << endl;
		cout << "2.学生" << endl;
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
			cout << "输入有误，请重新输入." << endl;
		}
	}
	system("pause");
	system("cls");
}

void printComputer(computerRoom com) {
	cout << "机房号 : " << com.room_id << "机房容量:" << com.room_cap << endl;
}

void admin::loadComputerInfo() {
	// 加载机房信息
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
		cout << "暂无可用的机房..." << endl;
	}
	ifs.close();
}

// 查看机房信息
void admin::showComputer() {
	cout << "展示机房信息" << endl;
	// 展示机房信息
	for_each(this->coms.begin(), this->coms.end(), printComputer);
}

// 清空预约记录
void admin::cleanOrder() {
	cout << "清除预约信息." << endl;
	cout << "清空后数据将丢失，请确认您真的要清空预约信息吗？" << endl;
	int sel = -1;
	while (true) {
		cout << "0.取消" << endl;
		cout << "1.确认" << endl;
		cin >> sel;
		if (sel == 0 || sel == 1) {
			break;
		}
		else {
			cout << "输入有误，请重新输入." << endl;
			system("pause");
			system("cls");
		}
	}
	if (sel == 1) {
		order od;
		od.ods.clear();
		od.updateAllOrder();
		cout << "情况完成" << endl;
		system("pause");
		system("cls");
	}

}


void printStu(student &st) {
	cout << "学生姓名:" << st.m_name << "\t pwd:***" << "\t学生ID:" << st.s_id << endl;
}

void admin::printStudent() {
	for_each(this->studs.begin(), this->studs.end(), printStu);
}

void printTea(teacher &st) {
	cout << "老师姓名:" << st.m_name << "\t pwd: ***" << "\t老师ID:" << st.t_id << endl;
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
	//	cout << "学生数据不存在." << endl;
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
		//cout << "老师数据不存在." << endl;
	}
	ifs1.close();
}



void admin::addAdmin() {
	string name;
	string pwd;
	string sid;
	cout << "请输入管理员用户名 :" << endl;
	cin >> name;
	cout << "请输入管理员密码: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(ADMIN_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << endl;
	ofs.close();
}