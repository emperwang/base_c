#include <iostream>
#include <string>
#include "manager.h"

void manager::showInfo() {
	std::cout << "系统ID : " << this->m_id
		<< "\t姓名 :" << this->m_name
		<< "\t部门ID :" << this->depId
		<< "\t工作职责: " << this->getJob() << std::endl;
}

std::string manager::getJob() {
	return std::string("完成老板交代的任务");
}

manager::manager(int id, std::string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->depId = did;
}

manager::~manager() {

}