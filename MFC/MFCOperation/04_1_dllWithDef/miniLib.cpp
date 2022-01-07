// 04_1_dllWithDef.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "miniLib.h"

/*
	ʹ��def���� dll����syntax:
	LIBRARY modleName			; ����DLL������,���п�ʡ��
	DESCRIPTION ""				; ΪDLL����һ�����ܽ���, ���п�ʡ��
	EXPORTS entryname[=internalname] [@ordinal] [NONAME] [CONSTANT] [PRIVATE]

	entryname[=internalname]: entryname��ʾҪ�������������������,������������ֺ�DLL�ж�������Ʋ�ͬ,�����ʹ��internalname��˵��DLL���ڲ����������
	��: DLL�ڲ�������function2, ����Ҫ��������Ϊ���� f1, ���������д:
			EXPORTS f1=function2
		
	@ordinal: ����ʹ����ŵ�������, �������Ժ���������,@�����orinal��ʾ���. ����DLL�����������ŵ�����Ŷ����Ǻ�����,���������Ż�DLL�Ĵ�С,��������Ҫ����
			��ຯ���������.
	NONAME :  NONAME�ؼ���Ϊ��ѡ��,��ʾֻ��������ŵ���,�����ú�����(entryname) ����.
	CONSTANT: CONSTANT �ؼ���Ҳ�ǿ�ѡ��, ��ʾ�������Ǳ��������Ǻ���. ʹ��DLL����������������ñ���Ϊ__declspec(dllimport),����ֻ�ܰ�����������ɵ�ַ
	PRIVATE:
*/

// ����һ��ȫ�ֱ���,�����е���
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

// �ຯ������

CMath::CMath(){}
CMath::~CMath() {}

double CMath::PI = 3.1415926;//  ��̬������ֵ
int CMath::sub(int a, int b)
{
	return a - b;
}


// def�������ʵ��
COperator::COperator(){}
COperator::~COperator(){}

int COperator::add(int a, int b) 
{
	return a + b;
}
