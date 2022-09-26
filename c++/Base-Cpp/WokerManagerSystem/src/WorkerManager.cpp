#include <iostream>
#include <string>
#include <fstream>
#include "WorkerManager.h"
#include "worker.h"
#include "manager.h"
#include "Boss.h"
#include "employee.h"

using namespace std;

workerManager::workerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 1.�ļ�������
	if (!ifs.is_open()) {
		//cout << "�ļ�������." << endl;
		this->curWorkCount = 0;
		this->worksArr = NULL;
		this->fileIfEmpty = true;
		ifs.close();
		return;
	}

	// 2.�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) { // eof : end of file
		//cout << "�ļ�����Ϊ��.." << endl;
		this->curWorkCount = 0;
		this->worksArr = NULL;
		this->fileIfEmpty = true;;
		ifs.close();
		return;
	}

	// 3.�ļ�������������
	int num = this->getNum();
	// cout << "file num : " << num << endl;
	this->curWorkCount = num;
	this->worksArr = new worker*[num];
	this->fileIfEmpty = false;
	this->initEmp(num);
}

workerManager::~workerManager() {
	if (this->curWorkCount > 0 && this->worksArr != NULL) {
		int i = 0;
		for (; i < this->curWorkCount; i++) {
			delete this->worksArr[i];
		}
		delete[] this->worksArr;
		this->worksArr = NULL;
		this->curWorkCount = 0;
	}
}

void workerManager::initEmp(int num) {
	int i = 0;
	int id;
	string name;
	int did;
	// int num = this->getNum();
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	for (; i < num; i++) {
		ifs >> id;
		ifs >> name;
		ifs >> did;
		// cout << "id = " << id << "\t name =" << name << "\t did = " << did << endl;
		switch (did) {
		case 1:
			this->worksArr[i] = new employee(id, name, did);
			break;
		case 2:
			this->worksArr[i] = new manager(id, name, did);
			break;
		case 3:
			this->worksArr[i] = new boss(id, name, did);
			break;
		}
	}
	ifs.close();
}

int workerManager::getNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	ifs.close();
	return num;
}

void workerManager::showMenu() {
	cout << "****************************************************************" << endl;
	cout << "********************  ��ӭʹ��ְ������ϵͳ��********************" << endl;
	cout << "************************ 0.�˳�����ϵͳ ************************" << endl;
	cout << "************************ 1.����ְ����Ϣ ************************" << endl;
	cout << "************************ 2.��ʾְ����Ϣ ************************" << endl;
	cout << "************************ 3.ɾ����ְְ�� ************************" << endl;
	cout << "************************ 4.�޸�ְ����Ϣ ************************" << endl;
	cout << "************************ 5.����ְ����Ϣ ************************" << endl;
	cout << "************************ 6.���ձ������ ************************" << endl;
	cout << "************************ 7.��������ļ� ************************" << endl;
	cout << "****************************************************************" << endl;
}

void workerManager::exitSystem() {
	cout << "��лʹ��ְԱ����ϵͳ��" << endl;
	system("pause");
	exit(0);
}


void workerManager::addEmployInfo() {

	cout << "��������Ҫ��ӵ�Ա�������� : ";
	int count = 0;
	cin >> count;
	if (count > 0) {
		int sum = count + this->curWorkCount;
		worker ** newSpace = new worker*[sum]; // ���� workerָ������
		int i = 0;
		for (; i < this->curWorkCount; i++) {
			newSpace[i] = this->worksArr[i];
		}
		for (i = 0; i < count; i ++ ) {
			int id;
			string name;
			int did;
			cout << "��" << i+1 << "��Ա����id: " << endl;
			cin >> id;
			cout << "��" << i+1 << "��Ա����name: " << endl;
			cin >> name;
			cout << "��" << i+1 << "��Ա�������: " << endl;
			cout << "1. Ա��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
			cin >> did;
			
			worker *wk = NULL;
			switch (did) {
			case 1:
				wk = new employee(id, name, did);
				break;
			case 2:
				wk = new manager(id, name, did);
				break;
			case 3:
				wk = new boss(id, name, did);
				break;
			default:
				cout << "������Ч��ѡ��." << endl;
				count++;
				continue;
				break;
			}
			newSpace[this->curWorkCount + i] = wk;
		}
		// �ͷ�ԭ�пռ�
		delete[] this->worksArr;
		
		this->worksArr = newSpace;
		this->curWorkCount = sum;
		this->save();
		cout << "�������." << endl;
	}
	else if(count < 0 ){
		cout << "�����������0Ŷ.";
		return;
	}
	else { // count = 0;
		cout << "count == 0" << endl;
	}
	system("pause");
	system("cls");
}

// ������Ϣ���ļ���
void workerManager::save() {
	if(this->curWorkCount > 0){
		ofstream ofs;
		ofs.open(FILENAME, ios::out);
		int i = 0;
		for (; i < this->curWorkCount; i++) {
			ofs << this->worksArr[i]->m_id << " "
				<< this->worksArr[i]->m_name << " "
				<< this->worksArr[i]->depId << endl;
		}
		ofs.close();
	}
	else {
		cout << "no into to save." << endl;
	}
	
}


void workerManager::listAllEmploy() {
	if (this->curWorkCount <= 0) {
		cout << "ϵͳ��Ա������Ϊ��.." << endl;
	}
	else {
		int i = 0;
		for (; i < this->curWorkCount; i++) {
			this->worksArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void workerManager::deleteEmsInfo() {
	if (this->curWorkCount <= 0) {
		cout << "ϵͳ������Ա����Ϣ.." << endl;
	}
	else {
		cout << "����������ɾ����Ա����id: " << endl;
		int id;
		cin >> id;
		int idx = this->ifExists(id);
		if (idx > 0) {
			// �ͷ���Դ
			int i = idx;
			delete this->worksArr[idx];
			for (; i < this->curWorkCount; i++) {
				this->worksArr[i] = this->worksArr[i++];
			}
			this->curWorkCount--;
			this->save();
		}
		else {
			cout << "���޴���:" << id << endl;
		}
	}
}

int workerManager::ifExists(int id) {
	int idx = -1;
	if (this->curWorkCount <= 0) {
		cout << "��ѯ�������� : "<< id << endl;
	}
	else {
		int  i = 0;
		for (i; i < this->curWorkCount; i++) {
			if (this->worksArr[i]->m_id == id) {
				idx = i;
				break;
			}
		}
	}
	return idx;
}

void workerManager::updateEmsInfo() {
	cout << "�����Ҫ���µ��û���id: " << endl;
	int id;
	cin >> id;
	int idx = this->ifExists(id);

	if (idx != -1) {
		worker * wk = this->worksArr[idx];
		cout << "������Ҫ���ĵ��û�������:" << endl;
		cin >> wk->m_name;
		cout << "������Ҫ���ĵ��û��Ĳ���ID:" << endl;
		cin >> wk->depId;

		this->save();
	}
	else {
		cout << "update:���޴���.." << endl;
	}

}

void workerManager::findEmsInfo() {
	cout << "�����Ҫ���ҵ��û���id: " << endl;
	int id;
	cin >> id;
	int idx = this->ifExists(id);
	if (idx != -1) {
		this->worksArr[idx]->showInfo();
	}
	else {
		cout << "find: ���޴���.." << endl;
	}
}

void workerManager::sortEmsInfo() {
	if (this->curWorkCount <= 0) {
		cout << "��ϢΪ��." << endl;
	}
	else {
		cout << "��ѡ������ʽ: " << endl;
		cout << " 1.���� " << endl;
		cout << " 2.����" << endl;
		int i;
		cin >> i;
		int j = 0, k = 0;
		int minOrMax = 0;
		if (i == 1) {
			for (k = 0; k < this->curWorkCount; k++) {
				minOrMax = k;
				for (j = k+1; j < this->curWorkCount; j++) {
					if (this->worksArr[minOrMax]->m_id > this->worksArr[j]->m_id) {
						minOrMax = j;
					}
				}
				// ������Сֵ
				if(minOrMax != k){
					worker *tmp = this->worksArr[k];
					this->worksArr[k] = this->worksArr[minOrMax];
					this->worksArr[minOrMax] = tmp;
				}
			}
		}
		else if (i == 2) {
			for (k = 0; k < this->curWorkCount; k++) {
				minOrMax = k;
				for (j = k + 1; j < this->curWorkCount; j++) {
					if (this->worksArr[minOrMax]->m_id < this->worksArr[j]->m_id) {
						minOrMax = j;
					}
				}
				// ������Сֵ
				if (minOrMax != k) {
					worker *tmp = this->worksArr[k];
					this->worksArr[k] = this->worksArr[minOrMax];
					this->worksArr[minOrMax] = tmp;
				}
			}
		}
		else {
			cout << "input invalid. Do nothing." << endl;
		}
		this->save();
	}
}

void workerManager::clearAllInfo() {
	cout << "��ȷ��Ҫ����ɾ����? " << endl;
	cout << "1. ɾ�� " << endl;
	cout << "2. ȡ�� " << endl;
	int i = 0;
	cin >> i;
	if (i == 1) {
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		if (this->worksArr != NULL) {
			int i = 0;
			for (; i < this->curWorkCount; i++) {
				delete this->worksArr[i];
			}
			delete[] this->worksArr;
			this->curWorkCount = 0;
		}
	}
	else if (i == 2) {
		return;
	}
	else {
		cout << "Do nothing.." << endl;
	}
}



