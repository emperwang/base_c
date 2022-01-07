//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_ENUM_HEADER_H
#define CPLUSPLUS_ENUM_HEADER_H

#include <iostream>

enum class Color2{
    RED=2,
    YELLOW,
    BLUE
};

enum class Color3:char;  // 前向声明

// 定义
enum class Color3:char {
    RED = 'r',
    BLUE
};

void test_enum_class_function();


#endif //CPLUSPLUS_ENUM_HEADER_H
