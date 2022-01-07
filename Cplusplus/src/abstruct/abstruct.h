//
// Created by Sparks on 2021/8/22.
//

#ifndef CPLUSPLUS_ABSTRUCT_H
#define CPLUSPLUS_ABSTRUCT_H

#include <iostream>
/*
 * 纯虚函数: 没有函数体的虚函数
 * 1. 在抽象类中,成员函数内可以调用纯虚函数,在构造函数/析构函数内不能使用纯虚函数
 *      如果一个类从抽象类派生而来,它必须实现了基类中的所有纯虚函数,才能成为非抽象类
 * 抽象类: 包含纯虚函数的类
 * 抽象类至少包含一个纯虚函数
 * 1. 抽象类只能作为基类来派生新类使用
 * 2. 抽象类的指针和引用 -> 由抽象类派生出来的类的对象
 * 3. 抽象类不能创建对象
 */
class abstruct_class1{
private:
    int a;
public:
    // 纯虚函数
    virtual void show()=0;
};

class abstruct_class2{
private:
    int a;
public:
    // 纯虚函数
    virtual void f() = 0;
    // 内部成员 调用纯虚函数
    void g() {
        std::cout << "call pure virtual function .. " <<std::endl;
        this->f();
    }
};

// 没有实现纯虚函数,故abstruct_class_impl2也会变成一个 抽象类,不能创建对象
class abstruct_class_impl2:public abstruct_class2{

};

class abstruct_class_impl1: public abstruct_class2{
public:
    void f() override {
        std::cout << "impl1 implement pure virtual func. " <<std::endl;
    }
};

/*
 * 构造函数不能是虚函数, 而析构函数可以使虚析构函数
 * 例如:
 * 当基类指针指向派生类对象并删除对象时,我们可能希望调用适当的析构函数,如果析构函数不是虚拟的,则只能调用基类
 * 析构函数
 */
class abstruct_base{
public:
    virtual ~abstruct_base(){
        std::cout << "abstruct_base deconstructor .." << std::endl;
    }
};

class abstruct_base_derived:public abstruct_base{
public:
    ~abstruct_base_derived() override {
        std::cout << "abstruct_base_derived deconstructor.." <<std::endl;
    }
};

void abstruct_test_virtual_deconstructor();

void abstruct_test_impl1();

#endif //CPLUSPLUS_ABSTRUCT_H
