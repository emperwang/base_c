#ifndef QTMINILIBRARY_H
#define QTMINILIBRARY_H

#include "QTMiniLibrary_global.h"
// 导出类
class QTMINILIBRARY_EXPORT QTMiniLibrary
{
public:
    QTMiniLibrary();
    virtual ~QTMiniLibrary();

    //导出类函数
    int sub(int a, int b);

    // 导出静态变量
    static double PI;
};

// 导出函数
#ifdef __cplusplus
extern "C" {
#endif
QTMINILIBRARY_EXPORT int add(int a,int b);

#ifdef __cplusplus
}
#endif


#endif // QTMINILIBRARY_H
