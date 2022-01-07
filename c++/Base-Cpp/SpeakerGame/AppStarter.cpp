#include <iostream>
#include <string>
#include "speakerManager.h"
using namespace std;

#define DEBUG_SP 1

int main() {
	speakManager mg;
	// mg.printSpeakers();
	int select;
	while (true) {
		mg.shouMenu();
		cout << "请输入您的选择:" << endl;;
		cin >> select;
		switch (select) {
		case 0:		// 退出
			mg.exitSystem();
			break;
		case 1:		// 开始演讲比赛
			mg.startSpeach();
			break;
		case 2:		// 查看往届成绩
			mg.showHistoryRecord();
			break;
		case 3:
			mg.clearAllInfo();
			break;
		default:	// 输入错误
			cout << "输入有误，请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}