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

	// 1.文件不存在
	if (!ifs.is_open()) {
		//cout << "文件不存在." << endl;
		this->curWorkCount = 0;
		this->worksArr = NULL;
		this->fileIfEmpty = true;
		ifs.close();
		return;
	}

	// 2.文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) { // eof : end of file
		//cout << "文件内容为空.." << endl;
		this->curWorkCount = 0;
		this->worksArr = NULL;
		this->fileIfEmpty = true;;
		ifs.close();
		return;
	}

	// 3.文件存在且有内容
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
	cout << "********************  欢迎使用职工管理系统！********************" << endl;
	cout << "************************ 0.退出管理系统 ************************" << endl;
	cout << "************************ 1.增加职工信息 ************************" << endl;
	cout << "************************ 2.显示职工信息 ************************" << endl;
	cout << "************************ 3.删除离职职工 ************************" << endl;
	cout << "************************ 4.修改职工信息 ************************" << endl;
	cout << "************************ 5.查找职工信息 ************************" << endl;
	cout << "************************ 6.按照编号排序 ************************" << endl;
	cout << "************************ 7.清空所有文件 ************************" << endl;
	cout << "****************************************************************" << endl;
}

void workerManager::exitSystem() {
	cout << "感谢使用职员管理系统。" << endl;
	system("pause");
	exit(0);
}


void workerManager::addEmployInfo() {

	cout << "请输入您要添加的员工的数量 : ";
	int count = 0;
	cin >> count;
	if (count > 0) {
		int sum = count + this->curWorkCount;
		worker ** newSpace = new worker*[sum]; // 创建 worker指针数组
		int i = 0;
		for (; i < this->curWorkCount; i++) {
			newSpace[i] = this->worksArr[i];
		}
		for (i = 0; i < count; i ++ ) {
			int id;
			string name;
			int did;
			cout << "第" << i+1 << "个员工的id: " << endl;
			cin >> id;
			cout << "第" << i+1 << "个员工的name: " << endl;
			cin >> name;
			cout << "第" << i+1 << "个员工的身份: " << endl;
			cout << "1. 员工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
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
				cout << "输入无效的选项." << endl;
				count++;
				continue;
				break;
			}
			newSpace[this->curWorkCount + i] = wk;
		}
		// 释放原有空间
		delete[] this->worksArr;
		
		this->worksArr = newSpace;
		this->curWorkCount = sum;
		this->save();
		cout << "保存完成." << endl;
	}
	else if(count < 0 ){
		cout << "人数必须大于0哦.";
		return;
	}
	else { // count = 0;
		cout << "count == 0" << endl;
	}
	system("pause");
	system("cls");
}

// 保存信息到文件中
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
		cout << "系统中员工人数为空.." << endl;
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
		cout << "系统中暂无员工信息.." << endl;
	}
	else {
		cout << "请输入你想删除的员工的id: " << endl;
		int id;
		cin >> id;
		int idx = this->ifExists(id);
		if (idx > 0) {
			// 释放资源
			int i = idx;
			delete this->worksArr[idx];
			for (; i < this->curWorkCount; i++) {
				this->worksArr[i] = this->worksArr[i++];
			}
			this->curWorkCount--;
			this->save();
		}
		else {
			cout << "查无此人:" << id << endl;
		}
	}
}

int workerManager::ifExists(int id) {
	int idx = -1;
	if (this->curWorkCount <= 0) {
		cout << "查询暂无其人 : "<< id << endl;
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
	cout << "请出入要更新的用户的id: " << endl;
	int id;
	cin >> id;
	int idx = this->ifExists(id);

	if (idx != -1) {
		worker * wk = this->worksArr[idx];
		cout << "请输入要更改的用户的姓名:" << endl;
		cin >> wk->m_name;
		cout << "请输入要更改的用户的部门ID:" << endl;
		cin >> wk->depId;

		this->save();
	}
	else {
		cout << "update:查无此人.." << endl;
	}

}

void workerManager::findEmsInfo() {
	cout << "请出入要查找的用户的id: " << endl;
	int id;
	cin >> id;
	int idx = this->ifExists(id);
	if (idx != -1) {
		this->worksArr[idx]->showInfo();
	}
	else {
		cout << "find: 查无此人.." << endl;
	}
}

void workerManager::sortEmsInfo() {
	if (this->curWorkCount <= 0) {
		cout << "信息为空." << endl;
	}
	else {
		cout << "请选择排序方式: " << endl;
		cout << " 1.升序 " << endl;
		cout << " 2.降序" << endl;
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
				// 交换大小值
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
				// 交换大小值
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
	cout << "您确认要进行删除吗? " << endl;
	cout << "1. 删除 " << endl;
	cout << "2. 取消 " << endl;
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



