#include <iostream>
#include <string>
#include "Boss.h"

boss::boss(int id, std::string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->depId = did;
}

boss::~boss(){}

void boss::showInfo() {
	std::cout << "系统ID : " << this->m_id
		<< "\t姓名 :" << this->m_name
		<< "\t部门ID :" << this->depId
		<< "\t工作职责: " << this->getJob() << std::endl;
}


std::string boss::getJob() {
	return std::string("统筹公司，战略管理...");
}