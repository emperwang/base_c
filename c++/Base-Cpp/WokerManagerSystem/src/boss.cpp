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
	std::cout << "ϵͳID : " << this->m_id
		<< "\t���� :" << this->m_name
		<< "\t����ID :" << this->depId
		<< "\t����ְ��: " << this->getJob() << std::endl;
}


std::string boss::getJob() {
	return std::string("ͳ�﹫˾��ս�Թ���...");
}