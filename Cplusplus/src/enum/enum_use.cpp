//
// Created by Sparks on 2021/8/24.
//

#include "enum_header.h"

void test_enum_class_function(){
    Color2 r2 = Color2::RED;

    std::cout << "color2 red value : "<< static_cast<int>(r2) <<std::endl;

    char r3 = static_cast<char>(Color3::RED);
    std::cout << "color3 RED value : " << r3 << std::endl;
}

