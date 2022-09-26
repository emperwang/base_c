#ifndef __CLASSCONSTRUCTOR_H__
#define __CLASSCONSTRUCTOR_H__
#include <string>
// 验证构造函数 初始化方式
class People {
public:
	// 构造函数，析构函数
	People();
	~People();

	void showInfo();

	int id;
	std::string name;
	std::string addr;

};

#endif