//
// Created by Sparks on 2021/8/24.
//

#include "virtual.h"

void virdecon::test_no_virtual_deconstruct(){
    virdecon::Derived *d = new virdecon::Derived();
    virdecon::Base *b = d;

    delete b;
}

void virdecon::test_virtual_deconstruct(){
    virdecon::Derived1 *d = new virdecon::Derived1();
    virdecon::Base1 *b = d;
    delete b;
}


