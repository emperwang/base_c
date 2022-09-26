#include "speakerManager.h"

void speakManager::shouMenu() {
	cout << "*****************************************************" << endl;
	cout << "***************** ��ӭ�μ��ݽ����� ******************" << endl;
	cout << "***************** 1.��ʼ�ݽ��Ƚ� ********************" << endl;
	cout << "***************** 2.�鿴�����¼ ********************" << endl;
	cout << "***************** 3.��ձ�����¼ ********************" << endl;
	cout << "***************** 0.�˳��������� ********************" << endl;
	cout << "*****************************************************" << endl;
}

void speakManager::exitSystem() {
	cout << "��лʹ���ݽ�����ϵͳ. �ڴ���������һ�κ���." << endl;
	system("pause");
	exit(0);
}

void speakManager::startSpeach() {
	// ��һ�ֱ���
	// 1.��ǩ
	this->speakDraw();
	// 2.����
	this->speakContent();
	// 3. ��ʾ������Ϣ
	this->showScore();
	// �ڶ��ֱ���
	this->m_index++;
	// 1.��ǩ
	this->speakDraw();
	// 2.����
	this->speakContent();
	// 3. ��ʾ���ս��
	this->showScore();
	// 4. �������
	this->saveRecord();

	// ���¼���һ����Ϣ
	this->loadRecords();

	// ����������Ϣ���Ա��´ν���ʹ��
	this->initSpeach();
	this->createSpeaker();
}


void speakManager::saveRecord() {
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);	// ׷��ģʽ�������
	if (!this->vVectory.empty()) {
		for (vector<int>::iterator it = this->vVectory.begin(); it != this->vVectory.end(); it++) {
			ofs << *it << "," << this->speakers[*it].score[1] << ",";
		}
		ofs << endl;
		this->fileExists = true;
	}
	else {
		cout << "vVectory is empty. " << endl;
	}

	ofs.close();
}


void speakManager::speakDraw() {
	// �жϵڼ��۱���, Ȼ��Բ�ͬ���������г�ǩ
	vector<int> tmp;
	if (this->m_index == 1) {
		tmp = this->v1;
	}
	else {
		tmp = this->v2;
	}
	random_shuffle(tmp.begin(), tmp.end());
	
	cout << " ����������ѡ�ֵ�˳�� :" << endl;
	for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
}

void speakManager::speakContent() {

	multimap<double, int,greater<double>> groupScore;
	cout << "---------------------�� " << this->m_index << " �ֱ�����ʼ-------------" << endl;
	// 1.���ݱ����Ľ׶β�ͬ  �༭��ͬ������
	vector<int> tmp;
	if (this->m_index == 1) {
		tmp = this->v1;
	}
	else {
		tmp = this->v2;
	}

	// 2.�ֱ��ѡ�ֽ��д��,
		// 2-1 ���������speaker����
		// 2-2 �Է�����������  ��ѡ��ǰ����  �������ڶ��ֱ���������
	deque<double> scores;
	int num = 0;
	for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		num++;
		// 10������
		for (int i = 0; i < 10; i++) {
			scores.push_back(((double)(rand() % 401 + 600))/10.0);
		}

		/*for (deque<double>::iterator itq = scores.begin(); itq != scores.end(); itq++) {
			cout << *itq << " ";
		}
		cout << endl;*/

		// �Է�������
		sort(scores.begin(), scores.end(), greater<double>());
		scores.pop_back();
		scores.pop_front();
		double sum = accumulate(scores.begin(), scores.end(), 0.0);
		double avg = sum / (double)scores.size();
		this->speakers[*it].score[this->m_index - 1] = avg;
		scores.clear();
		
		/*cout << "name= " << this->speakers[*it].name << "�� �÷� = " 
			<< this->speakers[*it].score[this->m_index - 1] << endl;*/

		// �洢���� �� ����
		groupScore.insert(make_pair(avg, (*it)));
		if (num % 6 == 0) { // ÿ6��ѡ��һ��  ѡ��ǰ����  ������һ�����
			
							//for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
			//it != groupScore.end(); it++) {
			//	cout << "��� : " << it->second << "\t �ɼ� :" << it->first << endl;
			//}
			//cout << endl;


			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
			count < 3; it++, count++) {
				if (this->m_index == 1) {
					this->v2.push_back(it->second);
				}
				else {
					this->vVectory.push_back(it->second);
				}
			}
			groupScore.clear();
		}
	}
	system("pause");
}


void speakManager::loadRecords() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	// cout << "load record" << endl;
	if (!ifs.is_open()){
		cout << "�ļ�������" << endl;
		this->fileExists = false;
		ifs.close();
		return;
	}
	char c;
	ifs >> c;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��." << endl;
		this->fileExists = false;
		ifs.close();
		return;
	}

	// ˵���ļ����ڣ����ļ���Ϊ��
	this->fileExists = true;
	// �Ѷ�ȡ���ַ��Ż�
	ifs.putback(c);
	string line;
	int index = 0;
	while (ifs >> line){
		// cout << line << endl;
		vector<string> record;
		int pos = -1;
		int start = 0;
		while (true) {
			pos = line.find(",", start);
			if (pos != -1) {
				string tmp = line.substr(start, pos - start);
				// cout << "find value:" << tmp << "\tindex =" << index << "\t pos = " << pos << endl;
				start = pos + 1;
				record.push_back(tmp);
			}
			else {
				break;
			}
		}
		this->historyRecords.insert(make_pair(index++, record));
	}
	ifs.close();
}

void speakManager::showHistoryRecord() {
	if (this->fileExists) {
		for (map<int, vector<string>>::iterator it = this->historyRecords.begin(); it != this->historyRecords.end();
		it++) {
			int idx = 0;
			cout << "�ھ���� :" << it->second[0] << "   �ھ��ɼ�: " << it->second[1]
				<< "  �Ǿ���� :" << it->second[2] << "    �Ǿ��ɼ�: " << it->second[3]
				<< "  ������� :" << it->second[4] << "    �����ɼ�: " << it->second[5] << endl;
		}
	}
	else {
		cout << "�����ļ������ڻ�Ϊ��." << endl;
	}
	system("pause");
	system("cls");
}

void speakManager::showScore() {
	vector<int> ids;
	cout << "����ѡ�ֳɼ� :" << endl;
	if (this->m_index == 1) {
		ids = this->v2;
		
	}
	else {
		ids = this->vVectory;
	}
	for (vector<int>::iterator it = ids.begin(); it != ids.end(); it++) {
		cout<<"ѡ�ֱ��: "<< *it << "\t ѡ������: " << this->speakers[*it].name << " \t ѡ�ֵ÷� : "
			<< this->speakers[*it].score[this->m_index - 1] << endl;
	}

	system("pause");
}

void speakManager::createSpeaker() {
	string ids = "ABCDEFGHIJKL";
	for (int i = 0; i < ids.size(); i++) {
		// ����ѡ�ֵ�����
		string name = "ѡ��";
		name += ids[i];
		speaker sp;
		sp.name = name;
		// ѡ�ֵ�id��
		int id = i + 100001;
		sp.id = id;
		for (int j = 0; j < 2; j++) {
			sp.score[j] = 0;
		}
		// id �Լ�ѡ�ַ���������
		this->v1.push_back(id);
		this->speakers.insert(make_pair(id, sp));
	}
}

void speakManager::initSpeach() {
	this->m_index = 1;
	this->speakers.clear();
	this->v1.clear();
	this->v2.clear();
	this->vVectory.clear();
}

void speakManager::printSpeakers() {

	for (map<int, speaker>::iterator it = this->speakers.begin(); it != this->speakers.end(); it++) {
		cout << "name = " << it->second.name << "\t id = " << it->second.id << "\t ������= " 
			<< it->second.score[0] << endl;
	}

}

void speakManager::clearAllInfo() {
	cout << "���Ҫɾ������������? " << endl;
	cout << "1.ɾ��" << endl;
	cout << "2.��" << endl;
	int sel=0;
	cin >> sel;
	if(sel == 1){
		ofstream ofs;
		ofs.open(filename, ios::trunc);
		ofs.close();
		this->historyRecords.clear();
		this->v2.clear();
		this->vVectory.clear();
		this->m_index = 1;
		this->fileExists = false;

		cout << "������.." << endl;
	}
	system("pause");
	system("cls");
}

speakManager::speakManager() {
	this->initSpeach();
	this->createSpeaker();
	this->loadRecords();
}

speakManager::~speakManager() {

}