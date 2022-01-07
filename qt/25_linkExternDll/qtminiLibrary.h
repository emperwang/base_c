#ifndef QTMINILIBRARY_H
#define QTMINILIBRARY_H
#include <QtCore/qglobal.h>

class Q_DECL_IMPORT QTMiniLibrary
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
Q_DECL_IMPORT int add(int a,int b);

#ifdef __cplusplus
}
#endif


#endif // QTMINILIBRARY_H
