#ifndef _worker_h_
#define _worker_h_

#include <string>
class worker {
public:
	int m_id;
	std::string m_name;
	int depId;

	// 打印自己的信息
	virtual void showInfo() = 0;
	virtual std::string getJob() = 0;
};

#endif
