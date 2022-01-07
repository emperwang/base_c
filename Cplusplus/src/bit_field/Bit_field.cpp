//
// Created by Sparks on 2021/8/24.
//

#include "bitfield.h"

void bit_field::test_bit_field(){
    using namespace bit_field;
    struct stuff s1 = {1,3,5};
    std::cout << "s.field1 : " << s1.field1 << std::endl;
    std::cout << "s.field2 : " << s1.field2 << std::endl;
    std::cout << "s.field3 : " << s1.field3 << std::endl;
}
