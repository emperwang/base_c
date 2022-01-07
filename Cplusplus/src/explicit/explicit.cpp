//
// Created by Sparks on 2021/8/24.
//

#include "explicit.h"


void explicit_demo::doA(explicit_demo::A a){}

void explicit_demo::doB(explicit_demo::B b){}

void explicit_demo::test_explicit_function(){
    A a1(1);    // ok, 直接初始化
    A a2 = 1; // ok 复制初始化
    A a3{1};    // ok,直接列表初始化
    A a4 = {1};  // ok, 直接列表初始化
    A a5 = (A)1;  // ok, 允许static_cast 的显示转换

    doA(1);     // ok, 允许从int到A的隐式转换

    if (a1);    // ok, 使用转换函数A::operator bool()，实现从A到bool的隐式转换
    bool a6(a1);      // ok, 使用转换函数,A::operator bool() 实现从A到bool的隐式转换
    bool a7 = a1;   // ok, 使用转换函数A::operator bool() 实现从A到bool的隐式转换
    bool a8 = static_cast<bool>(a1);  //ok, static_cast 进行直接转换

    B b1(1);    // ok, 直接初始化
    //B b2= 1;  // error, 被explicit修饰的构造函数对象不可以复制初始化
    B b3{1};    // ok, 直接列表初始化
    //B b4 = {1}; // error, 被explicit修饰的构造函数不可以复制列表初始化
    B b5 = (B)1;    // ok, 允许static_cast 的显示转换
    //doB(1); // error, 被explicit 修饰的构造函数对象不可以从int到B的隐式转换

    if(b1); // ok, 被explicit修饰的转换函数 B::operator bool() 实现从B到bool的转换; 按语境转换
    bool b6(b1);    // ok, 按语境转换,使用转换函数 B::operator bool()

    //bool b7 = b1;   // error, 被explicit修饰的转换函数B::operator bool() 对象不可以隐式转换

    bool b8 = static_cast<bool>(b1);    // ok, static_cast 可以直接初始化
}

