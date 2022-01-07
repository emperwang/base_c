#pragma once
#include "worker.h"

class employee : public worker {
public:
	void showInfo();
	std::string getJob();

	employee(int id, std::string name , int did);
	~employee();
};