#include <iostream>
#include <string>
#include "employee.h"

void employee::showInfo() {
	std::cout << "系统ID : " << this->m_id
		<< "\t姓名 :" << this->m_name
		<< "\t部门ID :" << this->depId
		<< "\t工作职责: " << this->getJob() << std::endl;
}

std::string employee::getJob() {

	return std::string("完成经历交代的任务.");
}

employee::employee(int id, std::string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->depId = did;
}

employee::~employee() {

}