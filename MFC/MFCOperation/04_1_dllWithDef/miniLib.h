#pragma once
#include "stdafx.h"
VOID miniMsgBox(TCHAR *);
VOID miniPrint(TCHAR *);


// 导出类的静态变量
class __declspec(dllexport) CMath
{
public:
	CMath();
	virtual ~CMath();

	int sub(int, int);

	static double PI;
};

// 使用 def 文件 再次导出一个类
class COperator
{
public:
	COperator();
	virtual ~COperator();

	int add(int, int);
};
