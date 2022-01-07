#pragma once
#include <Windows.h>
#include <tchar.h>
#include <lmcons.h>
#include <VersionHelpers.h>
#include <initguid.h>
#include <ShlObj.h>
#include <KnownFolders.h>

class WinApiDemo
{
public:
	WinApiDemo();
	~WinApiDemo();
};

//****** һЩ����system��Ϣ��api
// ��ȡscreen size
void GetScreentSize();

// ����
void LockStation();

// ��ȡcomputer name
void getComputerName();

// ��ȡ�û���
void getUserName();

// ��ȡ��ǰĿ¼
void getCurrentDir();

// windows�İ汾
void getWindowsVersion();

// ��ȡ�ڴ�
void getMemory();

// ��ȡ�ĵ�Ŀ¼·��
void getDocPath();

// Driver names
void getDriverNames();

// get disk space
void getFreeDishSpace();

// ��ȡע����е���Ϣ
void getCpuSpeed();
