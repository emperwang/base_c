// 05_call_dll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>
#include "miniLib.h"
#include <iostream>

extern "C" VOID MsgBox(TCHAR* szMsg);

// 如果变量没有被_declspec(dllimport)修饰,则会被认为是 指针
extern _declspec(dllimport) int globalVal;

// 加载库
#pragma comment(lib,"04_winDLL")
#pragma comment(lib,"04_1_dllWithDef")

/*
主要用于测试 加载自定义的lib库,并进行调用
这是加载静态库的使用
*/
int main()
{
	//  打印 globalVal 的值
	TCHAR buf[1024];
	wsprintf(buf, _T("Val = %d"), globalVal);
	MessageBox(nullptr,buf, _T("info"),MB_OK);
	// 修改全局变量的值,并再次输出
	globalVal = 888;
	std::cout << globalVal << std::endl;

	// 打印导出的类的静态内部变量
	std::cout << CMath::PI << std::endl;
	//调用打出的类 CMath
	CMath math;
	std::cout << "sub result = " << math.sub(1000, 200) << std::endl;

	// 调用使用 def文件导出的COperator类
	COperator oper;
	int resutl = oper.add(100, 100);
	std::cout << "result = " << resutl << std::endl;


	miniMsgBox(_T("call dll define with def file"));
	miniPrint(_T("call mini print export with def file"));
	MsgBox(_T("Hello First Lib"));
    return 0;
}

