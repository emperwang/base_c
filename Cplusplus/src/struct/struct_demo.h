//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_STRUCT_DEMO_H
#define CPLUSPLUS_STRUCT_DEMO_H

#include <iostream>

namespace struct_demo{
struct Base {
    int v1;
public:
    int v2;
    virtual void print(){
        printf("%s\n", "Base struct..");
    }
    Base() {
        std::cout <<"Base construct " <<std::endl;
    }
    virtual ~Base(){
        std::cout << "Base deconstruct ." <<std::endl;
    }
};

struct Derived:Base {
    Derived(){
        std::cout << "construct Derived.. " <<std::endl;
    }

    virtual ~Derived() {
        std::cout << "Derived deconstruct "<<std::endl;
    }

public:
    int v2;
    void print(){
        printf("%s\n", "Derived");
    }
};

    void test_struct_extend();
}


#endif //CPLUSPLUS_STRUCT_DEMO_H
