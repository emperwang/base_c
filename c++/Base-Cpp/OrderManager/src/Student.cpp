#include "student.h"
#include "admin.h"
#include "comOrder.h"
student::student() {

}

student::student(string name, string pwd, string id) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->s_id = id;
}

// 操作菜单
void student::operMenu() {
	cout << "欢迎学生: " << this->m_name << " 登录." << endl;
	cout << "---------------------------\n";
	cout << "|1.申请预约		|\n";
	cout << "|2.查看我的预约	|\n";
	cout << "|3.查看所有预约	|\n";
	cout << "|4.取消预约		|\n";
	cout << "|5.注销登录		|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要进行的操作:" << endl;
}

// 订阅
void student::applyOrder() {
	cout << "申请预约. " << endl;
	admin ad;
	// 要预约的机房号 以及  时间
	int romid;
	int time;
	int flag = true;
	while (flag) {
		ad.showComputer();
		cout << "请输入要预约的机房号 :" << endl;
		cin >> romid;
		for (vector<computerRoom>::iterator it = ad.coms.begin(); it != ad.coms.end(); it++) {
			if (it->room_id == romid) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "输入有误，请重新输入." << endl;;
			system("pause");
			system("cls");
		}
	}
	flag = true;
	while (flag) {
		cout << "请输入要预约的时间 :" << endl;
		cout << "1.上午" << endl;
		cout << "2.下午" << endl;
		cin >> time;
		if (time == morning || time == afternoon) {
			flag = false;
		}
		if (flag) {
			cout << "输入有误，请重新输入." << endl;;
			system("pause");
			system("cls");
		}
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	// 房间号  预约人  预约人id		时间	状态
	ofs << romid << " " << this->m_name << " " << this->s_id << " " << time << " " << orderPorcess << endl;
	ofs.close();
}

string getStatus(int status) {
	switch (status) {
	case orderPorcess:
		return "审阅中";
	case orderReady:
		return "通过";
	case orderCancel:
		return "取消";
	case orderFailed:
		return "未通过";
	}
}

// 查看自己订阅
void student::showMyOrder() {
	order od;
	for (vector<order>::iterator it = od.ods.begin(); it != od.ods.end(); it++) {
		if (it->o_id == this->s_id) {
			cout << "订阅机房: " << it->romid << " 订阅人:" << it->o_name 
				<< "  订阅人id:" << it->o_id << " 订阅时间:" <<
				(it->time == 1 ? "上午" : "下午") 
				<<"  状态:"<< getStatus(it->status) << endl;
		}
	}
	//ifstream ifs;
	//ifs.open(ORDER_FILE, ios::in);
	//if (ifs.is_open()) {
	//	string romid;
	//	string name;
	//	string id;
	//	string time;
	//	string status;
	//	while (ifs >> romid && ifs >> name && ifs >> id && ifs >> time && ifs >> status) {
	//		if (id == this->s_id) {
	//			cout << "订阅机房: " << romid << " 订阅人:" << name << "  订阅人id:" << id << " 订阅时间:" <<
	//				(atoi(time.c_str()) == 1 ? "上午" : "下午") <<"  状态:"<< getStatus(atoi(status.c_str())) << endl;
	//		}
	//	}
	//}
	//else {
	//	cout << "文件不存在或为空." << endl;
	//}
	//ifs.close();
	system("pause");
	system("cls");
}
// 查看所有订阅
void student::showAllOrder() {
	order od;
	for (vector<order>::iterator it = od.ods.begin(); it != od.ods.end(); it++) {
		cout << "订阅机房: " << it->romid << " 订阅人:" << it->o_name
			<< "  订阅人id:" << it->o_id << " 订阅时间:" <<
			(it->time == 1 ? "上午" : "下午")
			<< "  状态:" << getStatus(it->status) << endl;
	}
	/*ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (ifs.is_open()) {
		string romid;
		string name;
		string id;
		string time;
		string status;
		while (ifs >> romid && ifs >> name && ifs >> id && ifs >> time && ifs >> status) {
			cout << "订阅机房: " << romid << " 订阅人:" << name << "  订阅人id:" << id << " 订阅时间:" <<
				(atoi(time.c_str()) == 1 ? "上午" : "下午") << "  状态:" << getStatus(atoi(status.c_str())) << endl;
		}
	}
	else {
		cout << "文件不存在或为空." << endl;
	}
	ifs.close();*/
	system("pause");
	system("cls");
}
void printOrder(order od) {
	cout << "订阅机房: " << od.o_id << " 订阅人:" << od.o_name << "  订阅人id:" << od.o_id  << " 订阅时间:" <<
		(od.time == 1 ? "上午" : "下午") << "  状态:" << getStatus(od.status) << endl;
}
// 取消订阅
void student::cancelOrder() {
	order odr;
	if (odr.ods.size() <= 0) {
		cout << "暂时没有预约信息." << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> orIdx;	// 记录一下预约的位置
	vector<order> toUpdate;
	int idx = 0, outputIdx = 1;
	for (vector<order>::iterator it = odr.ods.begin(); it != odr.ods.end(); it++) {
		idx++;
		if (it->status == orderPorcess && it->o_id == this->s_id) {
			orIdx.push_back(idx);
			toUpdate.push_back(*it);
		}
	}
	if (orIdx.size() <= 0) {
		cout << "目前没有待审核的预约信息." << endl;
		system("pause");
		system("cls");
		return;
	}
	int sel = 0;// 接收输入的预约号
	int result; // 接收审核的结果
	while (true) {
		for (vector<order>::iterator it = toUpdate.begin(); it != toUpdate.end(); it++) {
			cout << outputIdx << " ";
			printOrder(*it);
		}
		cout << "请输入要审核的预约 :" << endl;
		cin >> sel;
		if (sel > 0 && sel <= orIdx.size()) {
			break;
		}
		else {
			cout << "输入有误，请重新输入要审核的预约号." << endl;
			system("pause");
			system("cls");
		}
	}
	odr.ods.at(orIdx.at(sel - 1) - 1).status = orderCancel;
	odr.updateAllOrder();
	cout << "取消成功 ." << endl;
	system("pause");
	system("cls");
}

/*
取消预约
ifstream ifs;
ifs.open(ORDER_FILE, ios::in);

if (!ifs.is_open()) {
	cout << "目前没有预约." << endl;
	ifs.close();
	system("pause");
	system("cls");
	return;
}
char c;
ifs >> c;

if (ifs.eof()) {
	cout << "目前没有预约的信息." << endl;
	ifs.close();
	system("pause");
	system("cls");
	return;
}

// 文件存在，且不为空
string romid;
string name;
string id;
string time;
string status;
ifs.putback(c);
vector<order> orders;
int idx = 1;
int sel = 0; // 记录输入值
while (ifs >> romid && ifs >> name && ifs >> id && ifs >> time && ifs >> status) {
	int sta = atoi(status.c_str());
	if (id == this->s_id && sta == orderPorcess) {
		order od(atoi(romid.c_str()), name, id, atoi(time.c_str()), sta);
		orders.push_back(od);
	}
}
ifs.close();
if (orders.size() <= 0) {
	cout << "目前还没有 " << this->m_name << "  的预约信息." << endl;
	system("pause");
	system("cls");
	return;
}

while (true) {
	for (vector<order>::iterator it = orders.begin(); it != orders.end(); it++) {
		cout << idx++ << " ";
		printOrder(*it);
	}
	cout << "请输入你要取消的预约:" << endl;
	cin >> sel;
	if (sel > 0 && sel <= orders.size()) {
		orders.at(sel - 1).status = orderCancel;
		// cout << "修改后的值: " << endl;
		// 重新写入文件
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::trunc);
		for (vector<order>::iterator it = orders.begin(); it != orders.end(); it++) {
			// printOrder(*it);

			// // 房间号  预约人  预约人id		时间	状态
			ofs << it->romid << " " << it->o_name << " " << it->o_id << " " << it->time << " "
				<< it->status << endl;
		}
		ofs.close();
		break;
	}
	else {
		idx = 1;
		cout << "输入有误，请重新输入. " << endl;
		system("pause");
		system("cls");
	}
}*/