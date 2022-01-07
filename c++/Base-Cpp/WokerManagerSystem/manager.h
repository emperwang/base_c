#ifndef __manager_h_
#define __manager_h_
#include <iostream>
#include "worker.h"

class manager : public worker {
public:
	void showInfo();
	std::string getJob();

	manager(int id, std::string name, int did);
	~manager();
};

#endif
