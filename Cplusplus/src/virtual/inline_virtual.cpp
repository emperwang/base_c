//
// Created by Sparks on 2021/8/24.
//
#include "virtual.h"

/*
 * 通常类成员函数都会被编译器考虑是否进行内联. 但通过基类指针或引用调用的虚函数必定不能被内联.
 * 当然,实体对象调用虚函数或者静态调用时可以被内联,虚析构函数的静态调用也一定会被内联展开
 * 1.虚函数可以使内联函数,内联是可以修饰虚函数的, 但是当虚函数表现多态性的时候不能内联
 * 2.内联是在建议编译器进行内联, 而虚函数的多态性在运行期, 编译器无法知道运行期调用哪个代码,
 *      因此虚函数表现为多态性时不可以内联
 * 3.inline virtual唯一可以内联的时候是:编译器知道所调用的对象是哪个类,
 *      这只有在编译器具有实际对象而不是对象的指针或引用时才会发生
 */

void inlinevirtual::test_inline_virtual(){
    inlinevirtual::Base b;
    // 可以被内联
    b.who();

    // 多态性,不可内联
    inlinevirtual::Base *ptr = new inlinevirtual::Derived();
    ptr->who();

    delete ptr;
}






