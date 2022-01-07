//
// Created by Sparks on 2021/8/24.
//

#include "virtual.h"

void virutalfunc::test_private_virtual_func(){
    virutalfunc::Base *ptr = new virutalfunc::Derived;
    ptr -> fun();
}

void virutalfunc::test_public_parent_virtual_func(){
    virutalfunc::Base1 *ptr = new virutalfunc::Derived1;
    ptr -> fun();
}
