//
// Created by Sparks on 2021/8/20.
//
#include "static_var.h"

class Person {
public:
    Person():i(0){
        std::cout << "person constructor .. " << std::endl;
    }

    Person(int num):i(num) {
        std::cout << "person constructor .. " <<std::endl;
    }

    ~Person(){
        std::cout<<"deConstructor Person.." << std::endl;
    }

    // 静态成员函数
    // 静态成员函数只能访问静态成员变量和函数, 不可以访问其他非静态的数据成员和函数
    static void say_hi(){
        std::cout<< "this is Person say hi to you .." << std::endl;
    }

private:
    int i;
};

void test_static_func_in_class(){
    Person::say_hi();
}

void test_static_class_scope(){
    int i=0;
    {
        // 此变量的scope为此 花括号,所以当出了此花括号时, 此变量就会被析构
        Person p;
    }

    {
        // 此静态变量生命周期是贯穿程序的始末,故出了此花括号,比变量并不会被析构
        static Person p2;
    }
}



