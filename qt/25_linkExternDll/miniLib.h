#ifndef MINILIB_H
#define MINILIB_H
#include <Windows.h>
#include <tchar.h>
extern "C" VOID miniMsgBox(TCHAR *);
extern "C" VOID miniPrint(TCHAR *);

class __declspec(dllimport) CMath
{
public:
    CMath();
    virtual ~CMath();

    int sub(int, int);

    static double PI;
};

class COperator
{
public:
    COperator();
    virtual ~COperator();

    int add(int, int);
};
#endif // MINILIB_H
