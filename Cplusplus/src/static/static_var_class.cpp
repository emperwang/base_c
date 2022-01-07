//
// Created by Sparks on 2021/8/20.
//
#include "static_var.h"


/*
 * static 成员变量在class内部的使用
 */

class static_apple{
public:
    static int api;
    static_apple(){}
    ~static_apple(){}
};

int static_apple::api = 100;

void test_static_variable_class(){
    static_apple app1;
    static_apple app2;
    // 多个class 共享同一个static内部变量
    app1.api = 20;
    app2.api = 200;

    std::cout << "app1 api num: " << app1.api << ", app2 api num: " << app2.api << std::endl;
}
