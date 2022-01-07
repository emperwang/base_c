// 06_call_dll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include "miniLib.h"

typedef VOID(*PFun)(TCHAR *);
/*
加载动态 dll库的使用
*/
int main()
{
	HMODULE hModule = LoadLibrary(_T("04_winDLL"));
	if (hModule == NULL)
	{
		MessageBox(NULL, _T("04_winDLL.dll not exists..."),_T("DLL load error"),MB_OK);
		return -1;
	}
		
	PFun pFunMsg = (PFun)GetProcAddress(hModule, "MsgBox");
	if (!pFunMsg) // 获取函数失败
	{
		// 则获取失败号,并释放库,然后打印失败信息
		DWORD lastError = ::GetLastError();
		FreeLibrary(hModule);
		TCHAR buf[1024];
		wsprintf(buf, _T("Get function addr error: %d"), lastError);
		MessageBox(nullptr, buf, _T("error"), MB_OK);
		return 0;
	}
	else
	{
		// 调用函数,然后释放库
		pFunMsg(_T("Hello first DLL"));
		// 调用完后,释放库文件
		FreeLibrary(hModule);
	}

	//  调用导出全局变量
	hModule = ::LoadLibrary(_T("04_1_dllWithDef"));
	if (hModule == nullptr)
	{
		MessageBox(nullptr, _T("Load module 04_1_dllWithDef error"), _T("info"), MB_OK);
		return 0; 
	}
	int *globalVal;

	globalVal = (int *)GetProcAddress(hModule, "globalVal");
	if (!globalVal)
	{
		std::cout << "get globalVal error" << std::endl;
		FreeLibrary(hModule);
		return 0;
	}
	else 
	{
		int n = *globalVal;
		std::cout << "globalVal = " << n << std::endl;
		FreeLibrary(hModule);
	}

	// 调用导出的类
	CMath math;
	std::cout << "1000 - 100 = " << math.sub(1000, 100) << std::endl;
	// 调用导出的 类的static字段
	std::cout << "pi = " << math.PI << std::endl;

    return 0;
}

