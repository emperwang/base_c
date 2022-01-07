// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件: 
#include <windows.h>
#include <tchar.h>

// 如果是cpp 则添加 extern 声明
#ifdef __cplusplus
extern "C" {
#endif
	// 本例 使用__declspec(dllexport) 来声明 导出函数
	__declspec(dllexport) VOID MsgBox(TCHAR *szMsg);

#ifdef __cplusplus
}
#endif


// TODO:  在此处引用程序需要的其他头文件
