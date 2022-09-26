#ifndef __COMORDER_H__
#define __COMORDER_H__
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "globalFile.h"
using namespace std;

class order {
public:
	order();
	order(int romid, string name, string id, int time);
	order(int romid, string name, string id, int time, int status);

	// 加载所有的order信息
	void loadAllOrder();

	// 更新所有的order信息
	void updateAllOrder();

	// 预约的机房id
	int romid;
	// 预约人的姓名
	string o_name;
	// 预约人的id
	string o_id;
	// 预约的时间
	int time;
	// 预约的状态
	int status;

	// 记录所有的预约信息
	vector<order> ods;
};


#endif // !__COMORDER_H__

