//
// Created by Sparks on 2021/8/22.
//
#include "abstruct.h"

void abstruct_test_impl1(){
    abstruct_class_impl1 p2;
    abstruct_class2 *p  = &p2;
    p->g();
}

void abstruct_test_virtual_deconstructor(){
    abstruct_base *base = new abstruct_base_derived();

    delete base;
}



