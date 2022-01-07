//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_BITFIELD_H
#define CPLUSPLUS_BITFIELD_H

#include <iostream>
namespace bit_field{
    struct stuff{
        unsigned int field1 : 30;
        unsigned int        : 2;
        unsigned int field2 : 4;
        unsigned int        : 0;
        unsigned int field3 : 3;
    };

    void test_bit_field();
}

#endif //CPLUSPLUS_BITFIELD_H
