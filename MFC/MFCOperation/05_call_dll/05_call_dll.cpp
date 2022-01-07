// 05_call_dll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>
#include "miniLib.h"
#include <iostream>

extern "C" VOID MsgBox(TCHAR* szMsg);

// �������û�б�_declspec(dllimport)����,��ᱻ��Ϊ�� ָ��
extern _declspec(dllimport) int globalVal;

// ���ؿ�
#pragma comment(lib,"04_winDLL")
#pragma comment(lib,"04_1_dllWithDef")

/*
��Ҫ���ڲ��� �����Զ����lib��,�����е���
���Ǽ��ؾ�̬���ʹ��
*/
int main()
{
	//  ��ӡ globalVal ��ֵ
	TCHAR buf[1024];
	wsprintf(buf, _T("Val = %d"), globalVal);
	MessageBox(nullptr,buf, _T("info"),MB_OK);
	// �޸�ȫ�ֱ�����ֵ,���ٴ����
	globalVal = 888;
	std::cout << globalVal << std::endl;

	// ��ӡ��������ľ�̬�ڲ�����
	std::cout << CMath::PI << std::endl;
	//���ô������ CMath
	CMath math;
	std::cout << "sub result = " << math.sub(1000, 200) << std::endl;

	// ����ʹ�� def�ļ�������COperator��
	COperator oper;
	int resutl = oper.add(100, 100);
	std::cout << "result = " << resutl << std::endl;


	miniMsgBox(_T("call dll define with def file"));
	miniPrint(_T("call mini print export with def file"));
	MsgBox(_T("Hello First Lib"));
    return 0;
}

