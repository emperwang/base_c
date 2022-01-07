// 04_1_dllWithDef.cpp : 定义 DLL 应用程序的导出函数。
//

#include "miniLib.h"

/*
	使用def定义 dll基本syntax:
	LIBRARY modleName			; 定义DLL的名字,此行可省略
	DESCRIPTION ""				; 为DLL定义一个功能介绍, 此行可省略
	EXPORTS entryname[=internalname] [@ordinal] [NONAME] [CONSTANT] [PRIVATE]

	entryname[=internalname]: entryname表示要导出函数或变量的名字,如果导出的名字和DLL中定义的名称不同,则可以使用internalname来说明DLL中内部定义的名字
	如: DLL内部定义了function2, 现在要把它导出为函数 f1, 则可以这样写:
			EXPORTS f1=function2
		
	@ordinal: 允许使用序号导出函数, 而不是以函数名导出,@后面的orinal表示序号. 这样DLL导出表里面存放的是序号而不是函数名,这样可以优化DLL的大小,尤其是在要导出
			许多函数的情况下.
	NONAME :  NONAME关键字为可选项,表示只允许按照序号导出,不适用函数名(entryname) 导出.
	CONSTANT: CONSTANT 关键字也是可选项, 表示导出的是变量而不是函数. 使用DLL导出变量最好声明该变量为__declspec(dllimport),否则只能把这个变量当成地址
	PRIVATE:
*/

// 定义一个全局变量,并进行导出
int globalVal = 10;

VOID miniMsgBox(TCHAR *msg)
{
	if (msg == nullptr || lstrlen(msg) <= 0)
	{
		::MessageBox(nullptr, _T("dll with def file setup"), _T("def DLL"), MB_OK);
	}
	else 
	{
		::MessageBox(nullptr, msg, _T("def DLL"), MB_OK);
	}
}

VOID miniPrint(TCHAR *msg)
{
	std::cout << msg << std::endl;
}

// 类函数定义

CMath::CMath(){}
CMath::~CMath() {}

double CMath::PI = 3.1415926;//  静态变量赋值
int CMath::sub(int a, int b)
{
	return a - b;
}


// def导出类的实现
COperator::COperator(){}
COperator::~COperator(){}

int COperator::add(int a, int b) 
{
	return a + b;
}
