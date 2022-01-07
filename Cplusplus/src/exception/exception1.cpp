//
// Created by Sparks on 2021/9/1.
//
#include "exception.h"

// 可以吧异常抛出去
void test_throw_exception_function(){
    try {
        if (0 == 0) {
            throw "exception";
        }
        }catch(...) {
        std::cout << "int func "<<std::endl;
        throw 1;
    }
}

void test_catch_exception_function(){
    try {
        test_throw_exception_function();
    }catch (int n){
        std::cout<<"catch function: catch exception: " << n<< std::endl;
    }
}
