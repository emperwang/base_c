//
// Created by Sparks on 2021/8/22.
//

#ifndef CPLUSPLUS_FUNC_POINTER_H
#define CPLUSPLUS_FUNC_POINTER_H

#include <iostream>



// 定义一种新的数据类型, 不是变量.  此func是一个函数指针,指向返回值和参数都为空的函数
typedef void(*func)(void);

void myFunc();
void g1Func(int a);
void test_func_pointer();
#endif //CPLUSPLUS_FUNC_POINTER_H
