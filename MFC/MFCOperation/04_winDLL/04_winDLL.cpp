// 04_winDLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"



VOID MsgBox(TCHAR *szMsg)
{
	TCHAR szModuleName[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szModuleName, MAX_PATH);
	MessageBox(NULL, szMsg, szModuleName, MB_OK);
}


