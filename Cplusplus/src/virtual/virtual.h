//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_VIRTUAL_H
#define CPLUSPLUS_VIRTUAL_H

#include <iostream>

namespace vircon {
    class Base {
    public:
        Base() {}

        virtual ~Base() {}

        virtual void changeAttribute() = 0;

        static Base *create(int id);

        virtual Base *clone() = 0;
    };


    class Derived1 : public Base {
    public:
        Derived1() {
            std::cout << "Derived1 created .." << std::endl;
        }

        Derived1(const Derived1 &rhs) {
            std::cout << "Derived1 create by deep copy.." << std::endl;
        }

        ~Derived1() {
            std::cout << "Derived1 destroyed" << std::endl;
        }

        void changeAttribute() override {
            std::cout << "Derived1 attributes changed.." << std::endl;
        }

        Base *clone() override {
            return new Derived1(*this);
        }
    };

    class Derived2 : public Base {
    public:
        Derived2() {
            std::cout << "Derived2 created .." << std::endl;
        }

        Derived2(const Derived1 &rhs) {
            std::cout << "Derived2 create by deep copy.." << std::endl;
        }

        ~Derived2() {
            std::cout << "Derived2 destroyed" << std::endl;
        }

        void changeAttribute() override {
            std::cout << "Derived2 attributes changed.." << std::endl;
        }

        Base *clone() override {
            return new Derived2(*this);
        }
    };

    class Derived3 : public Base {
    public:
        Derived3() {
            std::cout << "Derived3 created .." << std::endl;
        }

        Derived3(const Derived1 &rhs) {
            std::cout << "Derived3 create by deep copy.." << std::endl;
        }

        ~Derived3() {
            std::cout << "Derived3 destroyed" << std::endl;
        }

        void changeAttribute() override {
            std::cout << "Derived3 attributes changed.." << std::endl;
        }

        Base *clone() override {
            return new Derived3(*this);
        }
    };

    class User {
    public:
        User() : pbase(nullptr) {
            int input;
            std::cout << "Enter Id(1,2,3): " << std::endl;
            std::cin >> input;
            while ((input != 1) && (input != 2) && (input != 3)) {
                std::cout << "Enter Id(1,2,3 only): " << std::endl;
                std::cin >> input;
            }
            pbase = Base::create(input);
        }

        ~User() {
            if (pbase) {
                delete pbase;
            }
        }

        void Action() {
            // clone
            Base *pNewBase = pbase->clone();
            //
            pNewBase->changeAttribute();
            delete pNewBase;
        }

    private:
        Base *pbase;
    };

    void test_virtual_contructor();
}


namespace copycon{
    class Base{
    public:

    };

    class Derived: public Base{
    public:
        Derived(){
            std::cout << "Derived created... " <<std::endl;
        }

        Derived(const Derived &rhs){
            std::cout<<"Derived create by deep copy.."<<std::endl;
        }
        ~Derived(){
            std::cout << "Derived destoryed.." <<std::endl;
        }
    };

    void test_copy_constructot();
}

namespace virdecon{
    class Base {
    public:
        Base(){
            std::cout << "constructing...base"<<std::endl;
        }

        ~Base(){
            std::cout << "deconstructing ... Base" << std::endl;
        }
    };

    class Derived: public Base{
    public:
        Derived(){
            std::cout <<"constructing ... Derived.."<<std::endl;
        }

        ~Derived(){
            std::cout<<"deconstructing... Derived."<<std::endl;
        }

    };

    void test_no_virtual_deconstruct();

    class Base1 {
    public:
        Base1(){
            std::cout << "constructing...Base1"<<std::endl;
        }

        virtual ~Base1(){
            std::cout << "deconstructing ... Base1" << std::endl;
        }
    };

    class Derived1: public Base1{
    public:
        Derived1(){
            std::cout <<"constructing ... Derived1.."<<std::endl;
        }

        ~Derived1(){
            std::cout<<"deconstructing... Derived1."<<std::endl;
        }

    };

    void test_virtual_deconstruct();
}
/*
 * 虚函数可以被私有化, 但有一些细节需要注意
 * 基类指针指向 派生类对象, 则调用派生类对象的函数.
 * 那么 test_private_virtual_func测试函数需要声明为Base类的友元函数,否则编译失败. 编译器报错: 无法访问私有函数
 * 当然,把基类声明为public,继承类为private,则该问题就不存在.
 */
namespace virutalfunc{
    class Base{
    private:
        virtual void fun(){
            std::cout<<"Base virtual func" << std::endl;
        }
        friend void test_private_virtual_func(); // 如果不声明友元,包无法访问fun函数
    };

    class Derived :public Base{
    public:
        void fun() override {
            std::cout<< "derived func"<<std::endl;
        }
    };

    void test_private_virtual_func();

    class Base1{
    public:
        virtual void fun(){
            std::cout<<"Base1 virtual func" << std::endl;
        }
        friend void test_private_virtual_func(); // 如果不声明友元,包无法访问fun函数
    };

    class Derived1:public Base1{
    private:
        void fun() override {
            std::cout<< "Derived1 func"<<std::endl;
        }
    };

    void test_public_parent_virtual_func();
}


namespace inlinevirtual{
    /*
     * 通常类成员函数都会被考虑是否进行内联
     * 但通过基类指针或引用调用的虚函数必定不能内联
     * 当然,实体对象调用虚函数或静态调用时可以被内联,虚析构函数的静态调用也一定会被内联展开
     */
    class Base{
        public:
            virtual void who(){
                std::cout << "I am base \n";
            }
    };

    class Derived : public Base {
    public:
        void who() override {
            std::cout << "i am Derived..\n";
        }
    };

    void test_inline_virtual();
}


namespace rtti{
    class B {
        virtual void fun(){}
    };

    class D :public B{

    };

    void test_dynamic_case();
}

#endif //CPLUSPLUS_VIRTUAL_H
