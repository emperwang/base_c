//
// Created by Sparks on 2021/8/24.
//
/*
 * 构造函数不可以声明为虚函数,同时除了inline之外,构造函数不允许使用其他任何关键字
 * 为什么构造函数不可以为虚函数?
 * 尽管虚函数表 vtable是在编译阶段就已经建立的, 但指向虚函数表的指针vptr是在运行阶段实例化对象时才产生的.
 * 如果类含有虚函数,编译器会在构造函数中添加代码来创建vpt,  问题来了:
 *      如果构造函数是虚的,  那么它需要vptr来访问vtable,可这个时候vptr还没有产生, 因此, 构造函数不可以为虚函数
 * 我们之所以使用虚函数,是因为需要在信息不全的情况下进行多态运行, 而构造函数是用来初始化实例的,实例的类型必须是明确的.
 * 因此,构造函数没有必要被声明为虚函数. 尽管构造函数不可以声明为虚函数,但是有些场景下确实需要"virtual copy constructor".
 * "虚复制构造函数" 的说明并不严谨, 其只是一个实现了对象复制的功能的类内函数. 举一个应用场景, 比如 剪切板功能.
 * 复制内容作为基类, 但派生类可能包含有问题,图片,视频等.
 * 我们只有在程序运行的时候才知道我们需要复制的具体是什么类型的数据
 */
#include "virtual.h"

void vircon::test_virtual_contructor(){
    User *u = new User();
    u->Action();

    delete u;
}

vircon::Base *vircon::Base::create(int id) {
    if (id == 1) {
        return new Derived1;
    } else if (id == 2) {
        return new Derived2;
    } else {
        return new Derived3;
    };
}







