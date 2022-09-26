#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>

using namespace std;

class computerRoom {
public:
	computerRoom(){}
	computerRoom(int rid, int rcp) {
		this->room_id = rid;
		this->room_cap = rcp;
	}

	// 机房号 以及 此机房的最大容量
	int room_id;
	int room_cap;
};

#endif // !__COMPUTER_H__

