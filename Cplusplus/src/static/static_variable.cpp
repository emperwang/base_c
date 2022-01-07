//
// Created by Sparks on 2021/8/20.
//
#include "static_var.h"
void static_variable_func(){
    // 静态变量,虽然作用域只是在本函数内,但是此变量只会分配一次,无论函数调用多少次,都会只用此同一个变量
    static int count = 0;
    std::cout << "static variable in function: " << count << std::endl;
    count++;
}

void test_static_variable_function(){
    for(int i = 0; i < 100; i++){
        static_variable_func();
    }
}


