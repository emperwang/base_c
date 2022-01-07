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

// һЩwindows��string ��غ�����ʹ��

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

// ʱ�����
void getLocalTime();

void getUTCTime();

void calcTime();

void formatData();

void getUpTime();

void getWindowsEpoch();

void compareTime();

void retriveTimeZone();
