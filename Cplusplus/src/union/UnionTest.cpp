//
// Created by Sparks on 2021/8/24.
//

#include "union.h"

void test_union_function(){
    UnionTest u;

    union {
        int e;
        double f;
    };

    std::cout << u.i << std::endl;
    // 全局匿名 union成员i赋值
    ::i = 100;
    std::cout << "global scope i : " <<::i << std::endl;
    /*
     * 匿名union在定义所在作用域可直接访问union成员
     */
    e = 500;
    std::cout << "local scope e: " <<e << std::endl;
}