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
	cout << "��ӭ��ʦ: " << this->m_name << " ��¼." << endl;
	cout << "---------------------------\n";
	cout << "|			|\n";
	cout << "|1.�鿴����ԤԼ	|\n";
	cout << "|2.���ԤԼ		|\n";
	cout << "|3.ע����¼		|\n";
	cout << "|			|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ���еĲ���:" << endl;
}

// �鿴����
void teacher::showAllOrder() {
	student stu;
	stu.showAllOrder();
}


string getStatus1(int status) {
	switch (status) {
	case orderPorcess:
		return "������";
	case orderReady:
		return "ͨ��";
	case orderCancel:
		return "ȡ��";
	case orderFailed:
		return "δͨ��";
	}
}

void printOrder1(order od) {
	cout << "���Ļ���: " << od.o_id << " ������:" << od.o_name << "  ������id:" << od.o_id << " ����ʱ��:" <<
		(od.time == 1 ? "����" : "����") << "  ״̬:" << getStatus1(od.status) << endl;
}

// ���
void teacher::validOrder() {
	order odr;
	if (odr.ods.size() <= 0) {
		cout << "��ʱû��ԤԼ��Ϣ." << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> orIdx;	// ��¼һ��ԤԼ��λ��
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
		cout << "Ŀǰû�д���˵�ԤԼ��Ϣ." << endl;
		system("pause");
		system("cls");
		return;
	}
	int sel=0;// ���������ԤԼ��
	int result; // ������˵Ľ��
	while (true) {
		for (vector<order>::iterator it = toUpdate.begin(); it != toUpdate.end(); it++) {
			cout << outputIdx << " ";
			printOrder1(*it);
		}
		cout << "������Ҫ��˵�ԤԼ :" << endl;
		cin >> sel;
		if (sel > 0 && sel <= orIdx.size()) {
			break;
		}
		else {
			cout << "������������������Ҫ��˵�ԤԼ��." << endl;
			system("pause");
			system("cls");
		}
	}
	while (true) {
		cout << "��������˵Ľ�� :" << endl;
		cout << "1.���ͨ��" << endl;
		cout << "2.��˲���" << endl;
		cin >> result;
		if (result == 1 || result == 2) {
			break;
		}
		else {
			cout << "�������˽������,���������� ." << endl;
			system("pause");
			system("cls");
		}
	}
	odr.ods.at(orIdx.at(sel - 1)-1).status = (result==1?orderReady:orderFailed);
	odr.updateAllOrder();
	cout << "������ ." << endl;
}
