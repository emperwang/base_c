// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

/*
ul_reason_for_call 对应一些调用的事件,如: process加载事件;  故通过此事件可以在一些加载时间点进行一些初始化或者资源释放动作
*/
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

