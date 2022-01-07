#include "stdafx.h"
#include "StringsOper.h"
#pragma comment(lib, "shlwapi.lib")

StringsOper::StringsOper()
{
}


StringsOper::~StringsOper()
{
}

// 注释掉的是宽字符, 然后翻译为中间函数
void ansicStringFunc()
{
	//wchar_t str[] = L"There are 15 pines";
	_TCHAR str[] = _T("There are 15 pines.");

	//wprintf(L"The length of the string is: %lld\n", wcslen(str));
	_tprintf(_T("The length of the string is %ld characters \n"), _tcslen(str));

	//wchar_t buf[20];
	_TCHAR buf[20];

	//wcscpy(buf, L"Wuthering");
	_tcscpy_s(buf, _T("WuThering"));
	//wcscat(buf, L" Height");
	_tcscat_s(buf, _T("Height\n"));
	//wprintf(buf);
	_tprintf(buf);

	/*if (wcscmp(L"rain", L"rainy") == CSTR_EQUAL)
	{
		wprintf(L"rain and rainy are equal strings\n");
	}
	else
	{
		wprintf(L"rain and rainy are not equal strings\n");
	}*/

	if (_tcscmp(_T("rain"), _T("rainy")) == CSTR_EQUAL)
	{
		_tprintf(_T("rain nad rainy are reual strings\n"));
	}
	else
	{
		_tprintf(_T("rain and rainy are not equal strings\n"));
	}
}



void getStringLength()
{
	char *name = "Jane";
	wchar_t *town = L"Bratislava";

	wprintf(L"The length of name string is %d\n", lstrlenA(name));
	wprintf(L"The length of town string is %d\n", lstrlenW(town));

}

void getStringlengthSafe()
{
	wchar_t str[] = L"ZetCode";
	size_t targetSize = 0;

	size_t size = sizeof(str);

	// length of bytes
	HRESULT r = StringCbLengthW(str, size, &targetSize);

	if (SUCCEEDED(r))
	{
		wprintf(L"The string has %ld bytes \n", targetSize);
	}
	else
	{
		wprintf(L"StringCbLengthW failed\n");
		return;
	}

	size = sizeof(str) / sizeof(wchar_t);

	r = StringCchLengthW(str, size, &targetSize);
	if (SUCCEEDED(r))
	{
		wprintf(L"The string has %ld characters\n", targetSize);
	}
	else
	{
		wprintf(L"StringCclengthW failed\n");
	}
}

void concatString()
{
	wchar_t *s1 = L"ZetCode, ";
	wchar_t *s2 = L"tutorials ";
	wchar_t *s3 = L"for ";
	wchar_t *s4 = L"programmers\n";

	int len = lstrlenW(s1) + lstrlenW(s2) + lstrlenW(s3) + lstrlenW(s4);
	wchar_t *buf = new wchar_t[len+1];

	lstrcpyW(buf, s1);
	lstrcatW(buf, s2);
	lstrcatW(buf, s3);
	lstrcatW(buf, s4);
	wprintf(buf);

	delete[] buf;
}


void convertString()
{
	_TCHAR str[] = _T("Europa");

	CharLower(str);
	_tprintf(_T("%s\n"),str);

	CharUpper(str);
	_tprintf(_T("%s\n"), str);
}


void stringCompare()
{
	wchar_t *s1 = L"Strong";
	wchar_t *s2 = L"strong";

	if (lstrcmpW(s1, s2) == 0)
	{
		wprintf(L"%ls and %ls are equal\n", s1, s2);
	}
	else {
		wprintf(L"%ls and %ls are not equal\n", s1, s2);
	}

	wprintf(L"When applying case insensitive comparison:\n");

	if (lstrcmpiW(s1, s2) == 0)
	{
		wprintf(L"%ls and %ls are equal\n", s1, s2);
	}
	else {
		wprintf(L"%ls and %ls are not equal\n", s1, s2);
	}

}

void fillBuf()
{
	SYSTEMTIME st = { 0 };
	wchar_t buf[128] = { 0 };

	GetLocalTime(&st);
	wsprintfW(buf, L"Today is %lu.%lu.%lu\n", st.wYear, st.wMonth, st.wDay);

	wprintf(buf);
}


void getStringTypes()
{
	wchar_t str[] = L"7 white, 3 red rose.\n";
	int alphas = 0;
	int digits = 0;
	int spaces = 0;
	int puncts = 0;
	int contrs = 0;

	int size = lstrlenW(str);
	WORD *types = new WORD[size];
	ZeroMemory(types, size);

	BOOL cv = GetStringTypeW(CT_CTYPE1, str, size, types);

	if (!cv)
	{
		wprintf(L"Could not get character types %ld\n", GetLastError());
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (types[i] & C1_ALPHA)
		{
			alphas++;
		}
		if (types[i] & C1_DIGIT)
		{
			digits++;
		}
		 if (types[i] & C1_SPACE)
		{
			spaces++;
		}
		 if (types[i] & C1_PUNCT)
		{
			puncts++;
		}
		 if (types[i] & C1_CNTRL)
		 {
			 contrs++;
		 }
	}

	wprintf(L"There are %ld letter(s), %ld digit(s), %ld space(s), %ld punctuation character(s) and %ld control characters(s)\n", alphas, digits, spaces, puncts, contrs);

	delete[] types;
}



void trimString()
{
	wchar_t str1[] = L"23tennis74";
	wchar_t str2[] = L"0123456789";

	wprintf(L"Original string: %ls\n", str1);

	BOOL  r = StrTrimW(str1, str2);
	if (r == TRUE)
	{
		wprintf(L"The StrTrim() trimmed some characters\n");
	}
	else {
		wprintf(L"No characters were trimmed \n");
	}

	wprintf(L"Trimmed string;%s\n", str1);
}

void convertStringToInt()
{
	wchar_t str1[] = L"512";
	wchar_t str2[] = L"0xAB12";
	int n = 0;

	BOOL r = StrToIntExW(str1, STIF_DEFAULT, &n);
	if (r == TRUE)
	{
		wprintf(L"The value is : %d\n", n);
	}
	else {
		wprintf(L"The first conversion failed\n");
	}


	r = StrToIntExW(str2, STIF_SUPPORT_HEX, &n);
	if (r == TRUE)
	{
		wprintf(L"The sec value is %d\n", n);
	}
	else
	{
		wprintf(L"The second conversion failed\n");
	}

}


void searchString()
{
	wchar_t buf[] = L"Today is a rainy day";
	wchar_t *searchWord = L"rainy";

	int len = wcslen(searchWord);

	LPWSTR pr = StrStrW(buf, searchWord);

	if (pr == NULL)
	{
		wprintf(L"No match..\n");
	}
	else 
	{
		wprintf(L"%.*ls is found\n", len, pr);
	}

}

#define BUF_LEN 8091
void safeGets()
{
	wchar_t buf[BUF_LEN] = { 0 };
	wprintf(L"Please input you name: \n");
	HRESULT r = StringCchGetsW(buf, ARRAYSIZE(buf));

	if (SUCCEEDED(r))
	{
		wprintf(L"you have entered:%s\n", buf);
	}
	else
	{
		wprintf(L"StringCcGets() failed\n");
	}
}

void safeCopy()
{
	wchar_t *sentence = L"Today is a rainy day";

	size_t size = wcslen(sentence) + 1;
	wchar_t *buf = new wchar_t[size];
	ZeroMemory(buf, size);

	HRESULT r = StringCchCopyW(buf, size, sentence);

	if (SUCCEEDED(r))
	{
		wprintf(L"%ls\n", buf);
	}
	else
	{
		wprintf(L"StringCchCopy() failed\n");
	}

	delete[] buf;
}

#define buf_len 256
void safeConcat()
{
	
	wchar_t buf[buf_len] = { 0 };
	HRESULT r = StringCchCatW(buf, buf_len, L"Hello ");

	if (FAILED(r))
	{
		wprintf(L"StringCchCatw failed\n");
	}

	r = StringCchCatW(buf, buf_len, L"three ");
	if (FAILED(r))
	{
		wprintf(L"StringCchCatW() failed\n");
	}

	wprintf(L"%ls \n", buf);
}



void safeFormat()
{
	wchar_t *word = L"table";
	int count = 6;
	wchar_t buf[BUF_LEN] = { 0 };

	wchar_t *line = L"There are %d %ls";

	HRESULT r = StringCchPrintfW(buf, ARRAYSIZE(buf), line, count, word);

	if (SUCCEEDED(r))
	{
		wprintf(L"%ls \n", buf);
	}
}


void getLocalTime()
{
	SYSTEMTIME st = { 0 };
	GetLocalTime(&st);

	wprintf(L"The Local time is : %02d:%02d:%02d.%06d\n", st.wHour, st.wMinute, st.wSecond,st.wMilliseconds);
}

void getUTCTime()
{
	SYSTEMTIME st = { 0 };
	GetSystemTime(&st);

	wprintf(L"The UTC time is : %02d:%02d:%02d.%06d\n", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
}


void calcTime()
{
	int s3econds = 60 * 60 * 3;
	SYSTEMTIME st = { 0 };
	FILETIME ft = { 0 };
	GetLocalTime(&st);

	wprintf(L"%04d-%02d-%02d %02d:%02d:%02d.%06d\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	SystemTimeToFileTime(&st, &ft);

	ULARGE_INTEGER u = { 0 };
	memcpy(&u, &ft, sizeof(u));

	u.QuadPart += s3econds * 10000000LLU;
	memcpy(&ft, &u, sizeof(ft));

	FileTimeToSystemTime(&ft, &st);
	wprintf(L"%04d-%02d-%02d %02d:%02d:%02d.%06d\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
}


void formatData()
{
	PDWORD cChars = NULL;
	HANDLE std = GetStdHandle(STD_OUTPUT_HANDLE);


	if (std == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Cannot retrieve standard output handle %d\n", GetLastError());
		return;
	}

	SYSTEMTIME st = { 0 };
	GetLocalTime(&st);

	wchar_t buf[128] = { 0 };

	int r = GetDateFormatEx(LOCALE_NAME_USER_DEFAULT, DATE_LONGDATE, &st, NULL, buf, sizeof(buf) / sizeof(buf[0]), NULL);

	if (r == 0)
	{
		wprintf(L"GetDataFormatEx function failed\n");
		return;
	}

	WriteConsoleW(std, buf, wcslen(buf), cChars, NULL);

	r = CloseHandle(std);

	if (r == 0)
	{
		wprintf(L"Cannot close console handler %d\n,", GetLastError());
	}

}


void getUpTime()
{
	DWORD tc = GetTickCount();
	short seconds = tc / 1000;
	short minutes = tc / 1000 / 60;
	short hours = tc / 1000 / 60 / 60;
	short days = tc / 1000 / 60 / 60 / 24;

	wprintf(L"Computer has been run for sec: %d, minutes: %d, hours: %d, days: %d \n", seconds, minutes,hours, days);
}



void getWindowsEpoch()
{
	FILETIME ft = { 0 };
	GetSystemTimeAsFileTime(&ft);

	LARGE_INTEGER lg = { 0 };
	lg.LowPart = ft.dwLowDateTime;
	lg.HighPart = ft.dwHighDateTime;

	long long int hns = lg.QuadPart;

	wprintf(L"%lli hundreds of nanoseconds have elapsed since windows api epoch:\n", hns);

}

void compareTime()
{
	SYSTEMTIME st1 = { 0 };
	SYSTEMTIME st2 = { 0 };

	FILETIME ft1 = { 0 };
	FILETIME ft2 = { 0 };

	st1.wYear = 2015;
	st1.wMonth = 4;
	st1.wDay = 12;

	st2.wYear = 2016;
	st2.wMonth = 4;
	st2.wDay = 12;

	int r1 = SystemTimeToFileTime(&st1, &ft1);
	int r2 = SystemTimeToFileTime(&st2, &ft2);

	short ct = CompareFileTime(&ft1, &ft2);
	if (ct == -1)
	{
		wprintf(L"12/4/2015 before 12/4/2016\n");
	}
	else if (ct == 0)
	{
		wprintf(L"12/4/2015 equals 12/4/2016\n");
	}
	else if (ct == 1)
	{
		wprintf(L"12/4/2015 after 12/4/2016\n");
	}

}


void retriveTimeZone()
{
	TIME_ZONE_INFORMATION tzi = { 0 };
	int r = GetTimeZoneInformation(&tzi);

	if (r == TIME_ZONE_ID_INVALID)
	{
		wprintf(L"Failed to get time zone info\n");
		return;
	}

	wprintf(L"Time zone : %ls\n", tzi.StandardName);
	wprintf(L"Time zone bias: %ld minutes\n", tzi.Bias);
}
