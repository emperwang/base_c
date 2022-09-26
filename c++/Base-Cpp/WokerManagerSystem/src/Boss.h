#ifndef __Boss_h_
#define __Boss_h_
#include "worker.h"

class boss : public worker {
public:
	void showInfo();
	std::string getJob();

	boss(int id, std::string name, int did);
	~boss();
};

#endif
