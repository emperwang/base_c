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
		cout << "����������ѡ��:" << endl;;
		cin >> select;
		switch (select) {
		case 0:		// �˳�
			mg.exitSystem();
			break;
		case 1:		// ��ʼ�ݽ�����
			mg.startSpeach();
			break;
		case 2:		// �鿴����ɼ�
			mg.showHistoryRecord();
			break;
		case 3:
			mg.clearAllInfo();
			break;
		default:	// �������
			cout << "������������������." << endl;
			system("pause");
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}