//
// Created by Sparks on 2021/8/22.
//

#ifndef CPLUSPLUS_VPTR_H
#define CPLUSPLUS_VPTR_H

#include <iostream>

/*
 * 虚函数vptr 和 vtable
 * g++ -g -o vptr *.cpp -std=c++11
 */

typedef void (*vptrFun)();

class vptr_base{
public:
    vptr_base(){
        std::cout<<"vptr_base contructor.."<<std::endl;
    }

    virtual void func1(){
        std::cout<<"vptr func1" <<std::endl;
    }

    virtual void fun2(){
        std::cout <<"vptr fun2"<< std::endl;
    }
    virtual void func3(){

    }

    virtual ~vptr_base(){
        std::cout << "vptr decontructor.." <<std::endl;
    }
};

class vptr_impl: public vptr_base {
public:
    vptr_impl(){
        std::cout << "vptr impl "<<std::endl;
    }

    void func1() override {
        std::cout << "impl fun1 " <<std::endl;
    }

    void fun2() override {
        std::cout << "impl func2" << std::endl;
    }

    ~vptr_impl(){
        std::cout << "impl decontructor.."<<std::endl;
    }
};

/*
 * 获取vptr地址与func地址
 * vptr指向的是一块内存,这块内存存放的是虚函数地址,这块内存就是我们所说的虚表
 */
vptrFun getAddr(void* obj, int offset);

void test_vptr_table();

#endif //CPLUSPLUS_VPTR_H
