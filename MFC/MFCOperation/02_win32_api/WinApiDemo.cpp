#include "stdafx.h"
#include "WinApiDemo.h"


WinApiDemo::WinApiDemo()
{
}


WinApiDemo::~WinApiDemo()
{
}

void GetScreentSize()
{
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	_tprintf(_T("The screen size is : %d x %d\n"), x, y);
}

void LockStation()
{
	int r = LockWorkStation();

	if (r == 0)
	{
		_tprintf(_T("LocalWorkStation failed %d\n"), GetLastError());
	}
}


void getComputerName()
{
	_TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);

	int r = GetComputerName(computerName, &size);
	if (r == 0)
	{
		_tprintf(_T("Failed to get computer name: %ld\n"), GetLastError());
	}
	
	_tprintf(_T("Computer name: %s\n"), computerName);

}




void getUserName()
{
	_TCHAR userName[UNLEN + 1];
	DWORD len = sizeof(userName) / sizeof(userName[0]);

	int r = GetUserName(userName, &len);

	if (r == 0)
	{
		_tprintf(_T("Failed to get username: %ld\n"), GetLastError());
	}

	_tprintf(_T("user name: %s\n"), userName);

}

#define BUFSIZE MAX_PATH
void getCurrentDir()
{

	_TCHAR buf[BUFSIZE];

	_TCHAR curDir[] = { "D:\\ProgramFiles\\Msdn_2008\\Common" };
	DWORD r = SetCurrentDirectory(curDir);

	if (r == 0)
	{
		_tprintf(_T("SetCurrentDirectory failed (%d)\n"), GetLastError());
	}

	r = GetCurrentDirectory(BUFSIZE, buf);

	if (r == 0)
	{
		_tprintf(_T("GetCurrentDirectory failed %d\n"), GetLastError());
	}

	if (r > BUFSIZE)
	{
		_tprintf(_T("Buffer too small, need %d characters\n"), r);
	}

	_tprintf(_T("Current directory: %s\n"), buf);
}


void getWindowsVersion()
{
	if (IsWindows8Point1OrGreater())
	{
		_tprintf(_T("This is windows 8.1+\n"));
	}
	else if (IsWindows8OrGreater())
	{
		_tprintf(_T("This is windows 8\n"));
	}
	else if (IsWindows7OrGreater())
	{
		_tprintf(_T("this is windows 7\n"));
	}
	else if (IsWindowsVistaOrGreater())
	{
		_tprintf(_T("This is windows vista\n"));
	}
	else if (IsWindowsXPOrGreater())
	{
		_tprintf(_T("This is windows xp\n"));

	}
}



void getMemory()
{
	MEMORYSTATUSEX mem = { 0 };

	mem.dwLength = sizeof(mem);

	int r = GlobalMemoryStatusEx(&mem);

	if (r == 0)
	{
		_tprintf(_T("Failed to get memory status %d\n"), GetLastError());
		return;
	}

	_tprintf(_T("Memory in use: %ld percent \n"),mem.dwMemoryLoad );
	_tprintf(_T("Total physical memory %lld\n"),mem.ullTotalPhys );
	_tprintf(_T("Free physical memory : %lld\n"), mem.ullAvailPhys);
	_tprintf(_T("Total virtual memory: %lld\n"), mem.ullTotalVirtual);
	_tprintf(_T("Free virtual memory: %lld\n"), mem.ullAvailVirtual);
}

// some error
void getDocPath()
{
	PWSTR path = NULL;
	HRESULT hr = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path);

	if (SUCCEEDED(hr))
	{
		_tprintf(_T("%ls\n"), path);
	}
	CoTaskMemFree(path);
}



void getDriverNames()
{
	_TCHAR logicalDrivers[MAX_PATH] = { 0 };

	DWORD r = GetLogicalDriveStrings(MAX_PATH, logicalDrivers);

	if (r == 0)
	{
		_tprintf(_T("Failed to get driver name: %ld\n"), GetLastError());
		return;
	}

	if (r > 0 && r <= MAX_PATH)
	{
		_TCHAR *singleDriver = logicalDrivers;
		while (*singleDriver)
		{
			_tprintf(_T("%hs\n"), singleDriver);
			singleDriver += _tcslen(singleDriver) + 1;
		}
	}
}

void getFreeDishSpace()
{
	DWORD64  freeCall, total, free;

	int r = GetDiskFreeSpaceEx(_T("C:\\"), (PULARGE_INTEGER)&freeCall, (PULARGE_INTEGER)&total, (PULARGE_INTEGER)&free);

	if (r == 0)
	{
		_tprintf(_T("Failed to get free disk space %ld\n"), GetLastError());
		return;
	}

	_tprintf(_T("Available space to caller: %I64u MB\n"), freeCall / (1024 * 1024));
	_tprintf(_T("Total space : %I64u MB\n"), total / (1024 * 1024));
	_tprintf(_T("Free space : %I64u MB\n"), free / (1024 * 1024));
}

void getCpuSpeed()
{
	DWORD bufSize = MAX_PATH;
	DWORD mhz = MAX_PATH;
	HKEY key;

	long r = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0"), 0, KEY_READ, &key);

	if (r != ERROR_SUCCESS)
	{
		_tprintf(_T("RegOpenKeyEx() failed %ld\n"), GetLastError());
		return;
	}
	r = RegQueryValueEx(key, _T("~MHZ"), NULL, NULL, (LPBYTE)&mhz, &bufSize);
	if (r != ERROR_SUCCESS)
	{
		_tprintf(_T("RegQueryValue failed %ld\n"), GetLastError());
		return;
	}

	_tprintf(_T("CPU speed:: %lu MHZ\n"), mhz);
	_tprintf(_T("value size : %ld\n"), bufSize);

	r = RegCloseKey(key);

	if (r != ERROR_SUCCESS)
	{
		_tprintf(_T("Failed to close registry handler %ld\n"), GetLastError());
		return;
	}
}
