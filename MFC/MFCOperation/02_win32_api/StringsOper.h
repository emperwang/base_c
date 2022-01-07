#pragma once
#include <Windows.h>
#include <tchar.h>
#include <wchar.h>
#include <stdbool.h>
#include <shlwapi.h>
#include <strsafe.h>

class StringsOper
{
public:
	StringsOper();
	~StringsOper();
};

// 一些windows中string 相关函数的使用

void ansicStringFunc();

// string length
void getStringLength();

void getStringlengthSafe();

void concatString();


void convertString();

void stringCompare();

void fillBuf();

void getStringTypes();

void trimString();

void convertStringToInt();

void searchString();

void safeGets();

void safeCopy();

void safeConcat();

void safeFormat();

// 时间操作
void getLocalTime();

void getUTCTime();

void calcTime();

void formatData();

void getUpTime();

void getWindowsEpoch();

void compareTime();

void retriveTimeZone();
