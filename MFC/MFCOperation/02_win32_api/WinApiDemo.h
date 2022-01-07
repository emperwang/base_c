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

//****** 一些关于system信息的api
// 获取screen size
void GetScreentSize();

// 锁屏
void LockStation();

// 获取computer name
void getComputerName();

// 获取用户名
void getUserName();

// 获取当前目录
void getCurrentDir();

// windows的版本
void getWindowsVersion();

// 获取内存
void getMemory();

// 获取文档目录路径
void getDocPath();

// Driver names
void getDriverNames();

// get disk space
void getFreeDishSpace();

// 读取注册表中的信息
void getCpuSpeed();
