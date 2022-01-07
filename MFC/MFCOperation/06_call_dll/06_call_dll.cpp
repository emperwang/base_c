// 06_call_dll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include "miniLib.h"

typedef VOID(*PFun)(TCHAR *);
/*
���ض�̬ dll���ʹ��
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
	if (!pFunMsg) // ��ȡ����ʧ��
	{
		// ���ȡʧ�ܺ�,���ͷſ�,Ȼ���ӡʧ����Ϣ
		DWORD lastError = ::GetLastError();
		FreeLibrary(hModule);
		TCHAR buf[1024];
		wsprintf(buf, _T("Get function addr error: %d"), lastError);
		MessageBox(nullptr, buf, _T("error"), MB_OK);
		return 0;
	}
	else
	{
		// ���ú���,Ȼ���ͷſ�
		pFunMsg(_T("Hello first DLL"));
		// �������,�ͷſ��ļ�
		FreeLibrary(hModule);
	}

	//  ���õ���ȫ�ֱ���
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

	// ���õ�������
	CMath math;
	std::cout << "1000 - 100 = " << math.sub(1000, 100) << std::endl;
	// ���õ����� ���static�ֶ�
	std::cout << "pi = " << math.PI << std::endl;

    return 0;
}

