#include <iostream>
#include <string>
#include "manager.h"

void manager::showInfo() {
	std::cout << "ϵͳID : " << this->m_id
		<< "\t���� :" << this->m_name
		<< "\t����ID :" << this->depId
		<< "\t����ְ��: " << this->getJob() << std::endl;
}

std::string manager::getJob() {
	return std::string("����ϰ彻��������");
}

manager::manager(int id, std::string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->depId = did;
}

manager::~manager() {

}