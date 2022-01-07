#ifndef __SPEAKERMANAGER_H__
#define	__SPEAKERMANAGER_H__

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
#include "speaker.h"


using namespace std;

#define filename "speach.csv"

class speakManager {
public:
	//չʾ������
	void shouMenu();
	
	void initSpeach();

	// �˳�����
	void exitSystem();

	// ����ѡ��
	void createSpeaker();

	// ��ӡѡ����Ϣ
	void printSpeakers();

	// ��ʼ����
	void startSpeach();

	// ��ǩ
	void speakDraw();

	// ��������
	void speakContent();

	// ������Ϣ
	void saveRecord();

	// ��ʾ����ѡ����Ϣ
	void showScore();

	// �����������ݵ��ڴ�
	void loadRecords();

	// ��ʾ��ʷ��¼��Ϣ
	void showHistoryRecord();

	// ������м�¼
	void clearAllInfo();

	// ���캯��
	speakManager();
	// ��������
	~speakManager();


	// ����
	int m_index;	// �ڼ��α���
	vector<int> v1;	// ��һ�α����ı��
	map<int, speaker> speakers;  // �洢������
	vector<int> v2;	// �ڶ��αȽϵı��
	vector<int> vVectory; // ʤ����
	map<int, vector<string>> historyRecords;	// �����¼�洢
	bool fileExists;		// ���ݿ��ļ��Ƿ��д�
};


#endif // !