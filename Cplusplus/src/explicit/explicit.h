//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_EXPLICIT_H
#define CPLUSPLUS_EXPLICIT_H

#include <iostream>

/*
 * 1. explicit 修饰构造函数时, 可以防止隐式转换和复制初始化
 * 2. explicit 修饰转换函数时,可以防止隐式转换,但按语境转换外
 */
namespace explicit_demo{
struct A{
    A(int) {}
    operator bool() const { return true;}
};

struct B{
    explicit B(int) {}
    explicit operator bool() const {
        return true;
    }
};

void doA(A a);

void doB(B b);

void test_explicit_function();

}


#endif //CPLUSPLUS_EXPLICIT_H
