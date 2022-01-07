//
// Created by Sparks on 2021/8/20.
//

#include "Inline_A.h"

// 定义处 添加inline关键字，声明为内联函数
inline void Inline_A::Foo(int x, int y) {
    std::cout<< "Foo" << std::endl;
}

inline void Inline_A::f1(int x) {
    std::cout << "f1" << std::endl;
}
/*
 * 编译器inline函数的处理步骤
 * 将inline函数体复制到 inline 函数调用点处
 * 为所用inline函数中的局部变量分配内存空间
 * 将inline 函数的输入参数和返回值映射到 调用方法的局部变量空间中
 * 如果inline 函数有多个返回点, 将其转变为inline函数代码块末尾的分支(使用 goto) ????
 */


void test_inline_virtual_func(){
    // 此处的虚函数who(), 是通过类(Base)的具体对象(b)来调用的,编译器编译期间就能确定了
    // 所以它可以使内联的, 但最终是否内联 取决于编译器
    Base b;
    b.who();

    // 此处的虚函数是通过指针调用的,呈现多态性,需要在运行期间才能确定,所以不能内联
    Base *ptr = new Derived();
    ptr->who(); // 此处调用的是 Derived中的who函数

    // 因为Base有虚析构函数,所以delete时, 会先调用派生类的析构函数,再调用Base析构函数,防止内存泄漏
    delete ptr;
    ptr = nullptr;

}
