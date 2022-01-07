//
// Created by Sparks on 2021/8/22.
//
#include "func_pointer.h"

// 定义一个变量指针, 指向返回值为空 参数为int的函数
void (*jkpFunc)(int);

void myFunc(){
    std::cout << "return void and param void func" <<std::endl;
}

void g1Func(int a){
    std::cout << "g1func receive: " << a << std::endl;
}

void test_func_pointer(){
    // 定义一个func类型, 并进行赋值
    func pfun = myFunc;
    pfun();

    // 变量赋值
    jkpFunc = g1Func;
    (*jkpFunc)(5);
}


