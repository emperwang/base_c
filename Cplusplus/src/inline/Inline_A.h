//
// Created by Sparks on 2021/8/20.
//

#ifndef CPLUSPLUS_INLINE_A_H
#define CPLUSPLUS_INLINE_A_H

#include <iostream>

class Inline_A {
public:
    /*
     * 类中定义的函数是隐士内联函数,声明想要成为内联函数,必须在实现处(定义处)添加inline关键字
     */
    void f1(int x);

    // 函数内定义,即为隐式内联函数
    // 要想声明成为内联函数, 必须在定义处添加 inline关键字
    void Foo(int x, int y);
};


class Base{
public:
    inline virtual void who(){
        std::cout << "base who " <<std::endl;
    }
    virtual ~Base(){}
};

class Derived: public Base {
public:
    inline void who(){
        std::cout << "derived who"<<std::endl;
    }
};
/*
 * 1. 虚函数可以使内联函数, 内联是可以修饰虚函数的,但是当虚函数表现多态性的时候不能内联
 * 2. 内联是在编译期建议编译器内联,而虚函数的多态性在运行期,编译器无法知道运行期间是调用哪个函数,
 *  因此虚函数表现为多态时(运行期)不可以内联
 * 3. inline virtual唯一可以内联的时候是: 编译器知道所调用的对象是哪个类(如: Base::who()), 这只有在编译器
 * 具有实际对象而不是对象的指针或引用的时候才会发生
 */

void test_inline_virtual_func();

#endif //CPLUSPLUS_INLINE_A_H
