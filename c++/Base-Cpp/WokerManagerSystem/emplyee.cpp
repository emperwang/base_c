#include <iostream>
#include <string>
#include "employee.h"

void employee::showInfo() {
	std::cout << "ϵͳID : " << this->m_id
		<< "\t���� :" << this->m_name
		<< "\t����ID :" << this->depId
		<< "\t����ְ��: " << this->getJob() << std::endl;
}

std::string employee::getJob() {

	return std::string("��ɾ�������������.");
}

employee::employee(int id, std::string name, int did) {
	this->m_id = id;
	this->m_name = name;
	this->depId = did;
}

employee::~employee() {

}