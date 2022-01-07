//
// Created by Sparks on 2021/8/20.
//
#include "jksizeof.h"


// 空类大小为1字节
void get_black_class_size(){
    std::cout << "empty class size: " << sizeof(A) << std::endl;
}

void get_static_mem_size_class(){
    std::cout << "static member class:" << sizeof(static_mem_aclass) << std::endl;
}

void get_virtual_func_size_class(){
    std::cout << "virtual class size: " << sizeof(virtual_fun_class) <<std::endl;
}


void get_base_a_size(){
    std::cout <<"base a (char, int) size: " << sizeof(Base_A) <<std::endl;
}


void get_base_b_size(){
    std::cout << "impl base_a b size: " << sizeof(Base_B) << std::endl;
};


void get_base_c_wrapper_a(){
    std::cout << "wrapper a size："<< sizeof(Base_C )<<std::endl;
}

void get_virtual_impl_C(){
    std::cout << "virtual_impl_C size: " << sizeof(virtual_impl_C) <<std::endl;
}

void get_virtual_extend_size(){
    std::cout << "virtual extend size:" << sizeof(base_vir_c) << std::endl;
}









