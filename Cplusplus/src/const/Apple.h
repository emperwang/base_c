//
// Created by Sparks on 2021/8/20.
//

#ifndef CPLUSPLUS_APPLE_H
#define CPLUSPLUS_APPLE_H

#include <iostream>

class Apple {
private:
    int numbers[100];
public:
    Apple(int i);
    const int app_number;
    /*
     * static静态成员变量不能在类的内部初始化,内部只是声明,定义必须在类定义体的外部.通常在类的实现文件中初始化
     */
    static int pp;
    static const int apnum;

    void take(int num) const ;
    // 下面的两个函数为重载函数, const 是函数签名的一部分
    int add(int num);
    // 添加const 修饰符, 表示不会修改class内部的内容
    int add(int num) const;
    int getCount() const;
    ~Apple();
};


#endif //CPLUSPLUS_APPLE_H
