//
// Created by Sparks on 2021/8/20.
//

#include "Apple.h"

// 内部变量的初始化
const int Apple::apnum = 200;
int Apple::pp = 600;

Apple::Apple(int i):app_number(i) {}
Apple::~Apple() {
    std::cout << "deconstructor .. " <<std::endl;
}

// 非const函数可以调用 const函数
// const函数不可以调用 非const函数
int Apple::add(int num) {
    std::cout << "normal add " << std::endl;
    take(num);
    return 0;
}

int Apple::add(int num) const {
    std::cout << "add const " << std::endl;
    take(num);
    return 0;
}

void Apple::take(int num) const {
    std::cout << "task func, take num : " << num << std::endl;
}

int Apple::getCount() const {
    take(1);
    return app_number;
}