
// 01_MFC_Dialog.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy01_MFC_DialogApp: 
// �йش����ʵ�֣������ 01_MFC_Dialog.cpp
//

class CMy01_MFC_DialogApp : public CWinApp
{
public:
	CMy01_MFC_DialogApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy01_MFC_DialogApp theApp;