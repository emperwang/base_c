#ifndef __WorkerManager_h_
#define __WorkerManager_h_
#include "worker.h"

#define FILENAME  "info.txt"

class workerManager {
public:
	worker **worksArr;
	int curWorkCount;
	bool fileIfEmpty = true;

	// 构造以及析构函数
	workerManager();
	~workerManager();

	// 选择栏
	void showMenu();

	// 退出系统
	void exitSystem();

	// 添加职员信息
	void addEmployInfo();

	// 把员工信息保存到文件
	void save();

	// 获取文件中记录的个数
	int getNum();

	// 从文件中读取数据
	void initEmp(int num);

	// 打印员工信息
	void listAllEmploy();

	// 删除离职信息
	void deleteEmsInfo();

	// 是否存在指定id的员工,无 返回-1， 有则返回idx
	int ifExists(int id);

	// 更新员工信息
	void updateEmsInfo();
	// 查找员工
	void findEmsInfo();

	// 对id进行排序
	void sortEmsInfo();

	// 清除所有信息
	void clearAllInfo();
};

#endif
