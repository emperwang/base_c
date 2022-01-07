#include <iostream>
#include "WorkerManager.h"
using namespace std;


int main(int argc, char* argv[]) {
	int select;
	workerManager wm;

	while (true){
		wm.showMenu();
		cout << "����������ѡ�� : " << endl;
		cin >> select;
		// cout << "input value " << select << endl;
		switch (select) {
		case 0:				// �˳�����ϵͳ
			wm.exitSystem();
			break;
		case 1:				// ����ְ����Ϣ
			wm.addEmployInfo();
			break;
		case 2:				// ��ʾְ����Ϣ
			wm.listAllEmploy();
			break;
		case 3:				// ɾ����ְְ��
			wm.deleteEmsInfo();
			break;
		case 4:				// �޸�ְ����Ϣ
			wm.updateEmsInfo();
			break;
		case 5:				// ����ְ����Ϣ
			wm.findEmsInfo();
			break;
		case 6:				// ���ձ������
			wm.sortEmsInfo();
			break;
		case 7:				// ��������ļ�
			wm.clearAllInfo();
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}
