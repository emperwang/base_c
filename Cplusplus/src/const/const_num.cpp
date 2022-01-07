//
// Created by Sparks on 2021/8/19.
//
#include <iostream>
#include <string>
#include "const_num.h"

void const_num_test(){
    const int b = 10;
    // const 类型的变量 不可以被修改
    // b = 0;  //error
    const std::string s = "hello cplusplus";
    //const int i,j=0; // error, const 变量必须被初始化
    const int i = 0, j = 0;
    std::cout << "const b = "<< b << ", const string=" << s << ", const i = "<< i << ",const j = "<<j<<std::endl;
}
/*
 * 参数类型添加 const后,在函数内部就只能读取变量值,不能修改变量值
 */
void const_function_param(const int i){
    std::cout<<"const function param :  "<<i<<std::endl;
    //i = 10; // error
    std::cout<< "const function param can't be change" << std::endl;
}

/*
 * 使用其他文件声明的变量,变量未使用const修饰
 * 既然变量是其他文件声明的,需要告诉编译器,此变量是其他文件的
 */
extern int no_const_int;
void use_other_no_const_var(){
    std::cout<<"other variable: "<<no_const_int << std::endl;
}

// 声明要使用的const变量
extern const int const_int_var;
void use_other_const_var(){
    std::cout << "other file const var: " << const_int_var << std::endl;
}