#include <iostream>
#include "comOrder.h"


order::order(){
	this->loadAllOrder();
}

order::order(int romid, string name, string id, int time, int status) {
	this->romid = romid;
	this->o_name = name;
	this->o_id = id;
	this->time = time;
	this->status = status;
}

order::order(int romid, string name, string id, int time) {
	this->romid = romid;
	this->o_name = name;
	this->o_id = id;
	this->time = time;
}

void order::loadAllOrder() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (ifs.is_open()) {
		string romid;
		string name;
		string id;
		string time;
		string status;
		while (ifs >> romid && ifs >> name && ifs >> id && ifs >> time && ifs >> status) {
			order od(atoi(romid.c_str()), name, id, atoi(time.c_str()), atoi(status.c_str()));
			this->ods.push_back(od);
		}
	}
	ifs.close();
}


void order::updateAllOrder() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (vector<order>::iterator it = ods.begin(); it != ods.end(); it++) {

		// // 房间号  预约人  预约人id		时间	状态
		ofs << it->romid << " " << it->o_name << " " << it->o_id << " " << it->time << " "
			<< it->status << endl;
	}
	ofs.close();
}