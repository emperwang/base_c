#include "teacher.h"
#include "student.h"
#include "comOrder.h"


teacher::teacher() {

}
teacher::teacher(string name, string pwd, string tid) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->t_id = tid;
}
void teacher::operMenu() {
	cout << "欢迎老师: " << this->m_name << " 登录." << endl;
	cout << "---------------------------\n";
	cout << "|			|\n";
	cout << "|1.查看所有预约	|\n";
	cout << "|2.审核预约		|\n";
	cout << "|3.注销登录		|\n";
	cout << "|			|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要进行的操作:" << endl;
}

// 查看订阅
void teacher::showAllOrder() {
	student stu;
	stu.showAllOrder();
}


string getStatus1(int status) {
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

void printOrder1(order od) {
	cout << "订阅机房: " << od.o_id << " 订阅人:" << od.o_name << "  订阅人id:" << od.o_id << " 订阅时间:" <<
		(od.time == 1 ? "上午" : "下午") << "  状态:" << getStatus1(od.status) << endl;
}

// 审核
void teacher::validOrder() {
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
		if (it->status == orderPorcess) {
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
	int sel=0;// 接收输入的预约号
	int result; // 接收审核的结果
	while (true) {
		for (vector<order>::iterator it = toUpdate.begin(); it != toUpdate.end(); it++) {
			cout << outputIdx << " ";
			printOrder1(*it);
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
	while (true) {
		cout << "请输入审核的结果 :" << endl;
		cout << "1.审核通过" << endl;
		cout << "2.审核驳回" << endl;
		cin >> result;
		if (result == 1 || result == 2) {
			break;
		}
		else {
			cout << "输入的审核结果有误,请重新输入 ." << endl;
			system("pause");
			system("cls");
		}
	}
	odr.ods.at(orIdx.at(sel - 1)-1).status = (result==1?orderReady:orderFailed);
	odr.updateAllOrder();
	cout << "审核完成 ." << endl;
}
