// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>
#include <tchar.h>

// �����cpp ����� extern ����
#ifdef __cplusplus
extern "C" {
#endif
	// ���� ʹ��__declspec(dllexport) ������ ��������
	__declspec(dllexport) VOID MsgBox(TCHAR *szMsg);

#ifdef __cplusplus
}
#endif


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
