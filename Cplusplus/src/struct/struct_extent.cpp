//
// Created by Sparks on 2021/8/24.
//
#include "struct_demo.h"

void struct_demo::test_struct_extend(){
    using namespace struct_demo;
    Base *b = new Derived();
    b->print();
    delete b;
}
