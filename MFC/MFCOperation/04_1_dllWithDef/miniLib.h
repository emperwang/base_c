#pragma once
#include "stdafx.h"
VOID miniMsgBox(TCHAR *);
VOID miniPrint(TCHAR *);


// ������ľ�̬����
class __declspec(dllexport) CMath
{
public:
	CMath();
	virtual ~CMath();

	int sub(int, int);

	static double PI;
};

// ʹ�� def �ļ� �ٴε���һ����
class COperator
{
public:
	COperator();
	virtual ~COperator();

	int add(int, int);
};
