#include "speakerManager.h"

void speakManager::shouMenu() {
	cout << "*****************************************************" << endl;
	cout << "***************** 欢迎参加演讲比赛 ******************" << endl;
	cout << "***************** 1.开始演讲比较 ********************" << endl;
	cout << "***************** 2.查看往届记录 ********************" << endl;
	cout << "***************** 3.清空比赛记录 ********************" << endl;
	cout << "***************** 0.退出比赛程序 ********************" << endl;
	cout << "*****************************************************" << endl;
}

void speakManager::exitSystem() {
	cout << "感谢使用演讲比赛系统. 期待与您的下一次合作." << endl;
	system("pause");
	exit(0);
}

void speakManager::startSpeach() {
	// 第一轮比赛
	// 1.抽签
	this->speakDraw();
	// 2.比赛
	this->speakContent();
	// 3. 显示晋级信息
	this->showScore();
	// 第二轮比赛
	this->m_index++;
	// 1.抽签
	this->speakDraw();
	// 2.比赛
	this->speakContent();
	// 3. 显示最终结果
	this->showScore();
	// 4. 保存分数
	this->saveRecord();

	// 从新加载一次信息
	this->loadRecords();

	// 重新生成信息，以备下次进行使用
	this->initSpeach();
	this->createSpeaker();
}


void speakManager::saveRecord() {
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);	// 追加模式添加内容
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
	// 判断第几论比赛, 然后对不同的容器进行抽签
	vector<int> tmp;
	if (this->m_index == 1) {
		tmp = this->v1;
	}
	else {
		tmp = this->v2;
	}
	random_shuffle(tmp.begin(), tmp.end());
	
	cout << " 参数比赛的选手的顺序 :" << endl;
	for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
}

void speakManager::speakContent() {

	multimap<double, int,greater<double>> groupScore;
	cout << "---------------------第 " << this->m_index << " 轮比赛开始-------------" << endl;
	// 1.根据比赛的阶段不同  编辑不同的容器
	vector<int> tmp;
	if (this->m_index == 1) {
		tmp = this->v1;
	}
	else {
		tmp = this->v2;
	}

	// 2.分别对选手进行打分,
		// 2-1 保存分数到speaker对象
		// 2-2 对分数进行排序  并选出前三名  拷贝到第二轮比赛的容器
	deque<double> scores;
	int num = 0;
	for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		num++;
		// 10个分数
		for (int i = 0; i < 10; i++) {
			scores.push_back(((double)(rand() % 401 + 600))/10.0);
		}

		/*for (deque<double>::iterator itq = scores.begin(); itq != scores.end(); itq++) {
			cout << *itq << " ";
		}
		cout << endl;*/

		// 对分数排序
		sort(scores.begin(), scores.end(), greater<double>());
		scores.pop_back();
		scores.pop_front();
		double sum = accumulate(scores.begin(), scores.end(), 0.0);
		double avg = sum / (double)scores.size();
		this->speakers[*it].score[this->m_index - 1] = avg;
		scores.clear();
		
		/*cout << "name= " << this->speakers[*it].name << "， 得分 = " 
			<< this->speakers[*it].score[this->m_index - 1] << endl;*/

		// 存储分数 并 排序
		groupScore.insert(make_pair(avg, (*it)));
		if (num % 6 == 0) { // 每6个选手一组  选择前三名  进行下一组比赛
			
							//for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
			//it != groupScore.end(); it++) {
			//	cout << "编号 : " << it->second << "\t 成绩 :" << it->first << endl;
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
		cout << "文件不存在" << endl;
		this->fileExists = false;
		ifs.close();
		return;
	}
	char c;
	ifs >> c;
	if (ifs.eof()) {
		cout << "文件为空." << endl;
		this->fileExists = false;
		ifs.close();
		return;
	}

	// 说明文件存在，且文件不为空
	this->fileExists = true;
	// 把读取的字符放回
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
			cout << "冠军编号 :" << it->second[0] << "   冠军成绩: " << it->second[1]
				<< "  亚军编号 :" << it->second[2] << "    亚军成绩: " << it->second[3]
				<< "  季军编号 :" << it->second[4] << "    季军成绩: " << it->second[5] << endl;
		}
	}
	else {
		cout << "数据文件不存在或为空." << endl;
	}
	system("pause");
	system("cls");
}

void speakManager::showScore() {
	vector<int> ids;
	cout << "晋级选手成绩 :" << endl;
	if (this->m_index == 1) {
		ids = this->v2;
		
	}
	else {
		ids = this->vVectory;
	}
	for (vector<int>::iterator it = ids.begin(); it != ids.end(); it++) {
		cout<<"选手编号: "<< *it << "\t 选手姓名: " << this->speakers[*it].name << " \t 选手得分 : "
			<< this->speakers[*it].score[this->m_index - 1] << endl;
	}

	system("pause");
}

void speakManager::createSpeaker() {
	string ids = "ABCDEFGHIJKL";
	for (int i = 0; i < ids.size(); i++) {
		// 创建选手的姓名
		string name = "选手";
		name += ids[i];
		speaker sp;
		sp.name = name;
		// 选手的id号
		int id = i + 100001;
		sp.id = id;
		for (int j = 0; j < 2; j++) {
			sp.score[j] = 0;
		}
		// id 以及选手放入容器中
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
		cout << "name = " << it->second.name << "\t id = " << it->second.id << "\t 分数是= " 
			<< it->second.score[0] << endl;
	}

}

void speakManager::clearAllInfo() {
	cout << "真的要删除所有数据吗? " << endl;
	cout << "1.删除" << endl;
	cout << "2.否" << endl;
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

		cout << "清除完成.." << endl;
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