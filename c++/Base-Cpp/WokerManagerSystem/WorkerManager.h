#ifndef __WorkerManager_h_
#define __WorkerManager_h_
#include "worker.h"

#define FILENAME  "info.txt"

class workerManager {
public:
	worker **worksArr;
	int curWorkCount;
	bool fileIfEmpty = true;

	// �����Լ���������
	workerManager();
	~workerManager();

	// ѡ����
	void showMenu();

	// �˳�ϵͳ
	void exitSystem();

	// ���ְԱ��Ϣ
	void addEmployInfo();

	// ��Ա����Ϣ���浽�ļ�
	void save();

	// ��ȡ�ļ��м�¼�ĸ���
	int getNum();

	// ���ļ��ж�ȡ����
	void initEmp(int num);

	// ��ӡԱ����Ϣ
	void listAllEmploy();

	// ɾ����ְ��Ϣ
	void deleteEmsInfo();

	// �Ƿ����ָ��id��Ա��,�� ����-1�� ���򷵻�idx
	int ifExists(int id);

	// ����Ա����Ϣ
	void updateEmsInfo();
	// ����Ա��
	void findEmsInfo();

	// ��id��������
	void sortEmsInfo();

	// ���������Ϣ
	void clearAllInfo();
};

#endif
