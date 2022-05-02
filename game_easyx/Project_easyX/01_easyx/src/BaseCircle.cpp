#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include "easyxdemo.h"

/*
 error C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. To disable deprecation, 
 use _CRT_SECURE_NO_WARNINGS. See online help for details.

 针对这种报警, 定义这种宏来忽略警告

 #pragma warning (disable:4996)
 将4996 告警设置为失效
*/
#define _CRT_SECURE_NO_DEPRECATE

#pragma warning (disable:4996)
#pragma comment( lib, "MSIMG32.LIB")
#pragma comment(lib, "winmm.lib")    // 加载静态库

int main() {

	//firstCircle();
	//matrix();

	//PrintStars();

	//MouseOperation();
	//RainBow();
	playMp3();

	changeCmdMode();

	//std::system("pause");
	return 0;
}


