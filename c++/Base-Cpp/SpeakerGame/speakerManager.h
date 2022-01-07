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
	//展示标题栏
	void shouMenu();
	
	void initSpeach();

	// 退出操作
	void exitSystem();

	// 创建选手
	void createSpeaker();

	// 打印选手信息
	void printSpeakers();

	// 开始比赛
	void startSpeach();

	// 抽签
	void speakDraw();

	// 比赛内容
	void speakContent();

	// 保存信息
	void saveRecord();

	// 显示晋级选手信息
	void showScore();

	// 加载数据内容到内存
	void loadRecords();

	// 显示历史记录信息
	void showHistoryRecord();

	// 清空所有记录
	void clearAllInfo();

	// 构造函数
	speakManager();
	// 析构函数
	~speakManager();


	// 属性
	int m_index;	// 第几次比赛
	vector<int> v1;	// 第一次比赛的编号
	map<int, speaker> speakers;  // 存储比赛者
	vector<int> v2;	// 第二次比较的编号
	vector<int> vVectory; // 胜利者
	map<int, vector<string>> historyRecords;	// 往届记录存储
	bool fileExists;		// 数据库文件是否有错
};


#endif // !