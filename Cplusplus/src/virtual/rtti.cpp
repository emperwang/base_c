//
// Created by Sparks on 2021/8/24.
//
/*
 * RTTI(Run-Time Type Identification), 通过运行时类型信息程序能够使用基类的指针或引用来检查这些指针或引用
 * 所指的对象的实际派生类型
 * 在面向对象程序设计中,优势我们需要在运行时查询一个对象是否能够作为某种多态类型使用.与 java的instanceof
 * 以及c#的as,is运算符类似, c++提供了dynamic_cast函数用于动态转型. 相比c风格的强制类型转换和c++ reinterpret_cast,
 * dynamic_cast提供了类型安全检查,是一种基于能力查询(capability query)的转换,所以在多态类型期间进行转换更提倡使用
 * dynamic_cast.
 */
#include "virtual.h"
#include <typeinfo>

/*
 * 在使用dynamic_cast需要注意, 被转换对象obj的类型必须是多态类型, 即obj必须公有继承其他类,或者obj拥有虚函数(继承或自定义)
 * 如果obj非多态类型,使用dynamic_cast会报编译错误
 */
void rtti::test_dynamic_case(){
    using namespace rtti;
    B *b = new D; // 向上转型.
    B &obj = *b;    // 引用
    // 向下转型
    D *d = dynamic_cast<D*>(b);
    if (d){
        std::cout << "dynamic works.."<<std::endl;
    }else {
        std::cout << "can't case B* to D* "<<std::endl;
    }

    try {
        D& dobj = dynamic_cast<D&>(obj);
        std::cout << "cast D& works " <<std::endl;
    }catch (std::bad_cast bc){
        std::cout << bc.what() << std::endl;
    }


}


