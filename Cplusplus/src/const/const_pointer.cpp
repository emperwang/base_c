//
// Created by Sparks on 2021/8/20.
//
#include <iostream>
/*
 * 如果const位于*的左侧,则const就是用来修饰指针所指向的变量,即指针指向为常量
 * 如果const位于*的右侧,则const就是用来修饰指针本身的, 即指针本身是常量,即指针常量
 */

// 指向常量的指针
void point_const(){
    const int* p = nullptr;
    // 指针指向的变量为常量,故不可以通过指针来修改变量的值
    //*p = 5; // error

    const int var = 100;
    const int* pt = &var;
    // 非指向常量的指针,不能指向常量
    //int *nopt = &var; // error

    // 常量指针可以指向 非常量的变量
    const int*pt2 = nullptr;
    int tmpvar = 100;
    pt2 = &tmpvar; // 可以指向非常量的变量

    // 非常量变量,可以通过非常量的指针来修改其值
    int *pt3 = nullptr;
    pt3 = &tmpvar;
    *pt3 = 200;
    std::cout << "const pointer: " << *pt2 << ", no const pointer : " << *pt3 << std::endl;


    // 常量指针, 常量指针指向非常量值
    int tmp3 = 200;
    int * const pt4 = &tmp3;    // 常量指针必须初始化
    int * pt4_4 = &tmp3;
    *pt4_4 = 500;

    std::cout<<"const pointer: " << *pt4 << ", pt4_4: "<< *pt4_4 << std::endl;

    // 指向常量的常量指针
    const int tmp4 = 500;
    const int * const pt5 = &tmp4;
    std::cout << "const int * const pointer: " << *pt5 << std::endl;


}

