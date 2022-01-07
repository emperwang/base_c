//
// Created by Sparks on 2021/8/20.
//

#ifndef CPLUSPLUS_JKSIZEOF_H
#define CPLUSPLUS_JKSIZEOF_H

#include <iostream>
class A{};

/*
 * 静态数据成员
 * 静态数据成员被编译器放在程序的一个global data member中, 它是类的一个数据成员,但不影响类的大小.不管这个类产生了多少个实例
 * 还是派生了多少个新的类,静态数据成员只有一个实例. 静态数据成员 一旦被声明,就已经存在
 */

class static_mem_aclass{
public:
    char b;
    virtual void fun(){};
    static int c;
    static int d;
    static int f;
};

/*
 * 对于包含虚函数的类,不管有多少个虚函数,只有一个虚指针,vptr的大小
 */
class virtual_fun_class{
public:
    virtual void func();
    virtual void func1();
    virtual void func2();
    virtual void func3();

};

/*
 * 1. 普通单继承,继承就是基类+派生类自身的大小(注意字节对齐)
 * 注意:
 *      类的数据成员按其声明顺序加入内存, 与访问权限无关, 只看声明顺序
 * 2. 虚单继承, 派生类继承基类 vptr
 */

class Base_A{
public:
    char a;
    int b;
};
/*
 * 此时顺序就是:
 * char a
 * int b
 * short a
 * long b
 * 根据字节对齐就是 4+4+8+8=24
 */
class Base_B:public Base_A {
public:
    short a;
    long b;
};

class Base_C{
public:
    Base_A a;
    char c;
};

class virtual_base_A{
public:
    virtual void func(){};
};

//这里就 继承一个虚指针 vptr 8字节
class virtual_impl_C:public virtual_base_A{
};

/*
 * 虚继承
 */
class base_vir_a{
public:
    virtual void func(){}
};

class base_vir_b{
public:
    virtual void func2(){}
};

class base_vir_c: virtual public base_vir_a, virtual public base_vir_b{
public:
    virtual void func3(){}
};

void get_virtual_extend_size();

void get_black_class_size();
void get_static_mem_size_class();
void get_virtual_func_size_class();
void get_base_a_size();
void get_base_b_size();
void get_base_c_wrapper_a();
void get_virtual_impl_C();

#endif //CPLUSPLUS_JKSIZEOF_H
