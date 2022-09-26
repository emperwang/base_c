#include <iostream>
#include "WorkerManager.h"
using namespace std;


int main(int argc, char* argv[]) {
	int select;
	workerManager wm;

	while (true){
		wm.showMenu();
		cout << "请输入您的选择 : " << endl;
		cin >> select;
		// cout << "input value " << select << endl;
		switch (select) {
		case 0:				// 退出管理系统
			wm.exitSystem();
			break;
		case 1:				// 增加职工信息
			wm.addEmployInfo();
			break;
		case 2:				// 显示职工信息
			wm.listAllEmploy();
			break;
		case 3:				// 删除离职职工
			wm.deleteEmsInfo();
			break;
		case 4:				// 修改职工信息
			wm.updateEmsInfo();
			break;
		case 5:				// 查找职工信息
			wm.findEmsInfo();
			break;
		case 6:				// 按照编号排序
			wm.sortEmsInfo();
			break;
		case 7:				// 清空所有文件
			wm.clearAllInfo();
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}
