#include "qtminilibrary.h"

QTMiniLibrary::QTMiniLibrary()
{
}

QTMiniLibrary::~QTMiniLibrary()
{

}

//导出类函数
int QTMiniLibrary::sub(int a, int b)
{
    return a - b;
}

// 导出静态变量
double QTMiniLibrary::PI = 3.1415926;


int add(int a,int b)
{
    return a+b;
}
