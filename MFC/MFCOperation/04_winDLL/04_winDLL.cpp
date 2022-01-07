// 04_winDLL.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"



VOID MsgBox(TCHAR *szMsg)
{
	TCHAR szModuleName[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szModuleName, MAX_PATH);
	MessageBox(NULL, szMsg, szModuleName, MB_OK);
}


