//
// Created by Sparks on 2021/8/30.
//
#include "template.h"

template <typename T>
T template_ns::compareMax(T t1, T t2){
    std::cout << "template function "<<std::endl;
    return t1 > t2 ? t1 : t2;
}

template <>
const char* template_ns::compareMax<const char*>(const char*s1, const char *s2){
    std::cout << "[for debug]" << "call compareMax template" <<std::endl;
    return strcmp(s1, s2) >= 0? s1:s2;
}

void template_ns::test_template_function(){
    std::cout << "compareMax(1,2) = "<< compareMax(1, 2) <<std::endl;
    std::cout << "compareMax(1.0,2.0) = "<< compareMax(1.0, 2.0) <<std::endl;
    std::cout << "compareMax(str,str2) = " << compareMax("asda", "qwwq")<< std::endl;
}

//  动态数组测试
void template_ns::test_var_array(){
    // 指针创建
    char *sPtr;
    // 字符数组创建
    const char *s = "hello";
    // 动态数组创建
    sPtr = new char[strlen(s) + 1];
    // 数组拷贝
    strncpy(sPtr, s, strlen(s));
    // 输出数据
    std::cout << sPtr << std::endl;

    delete sPtr;
}
