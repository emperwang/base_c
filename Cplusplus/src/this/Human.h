//
// Created by Sparks on 2021/8/20.
//

#ifndef CPLUSPLUS_HUMAN_H
#define CPLUSPLUS_HUMAN_H

#include <iostream>
#include <cstring>

class Human {

public:
    typedef enum {
        BOY=0,
        GIRL
    }SexType;
    Human(const char*name, int a, SexType s);

    int get_age() const;

    Human& add_age(int a);

    ~Human();
private:
    char *name;
    int age;
    SexType sex;
};

void test_this_pointer();

#endif //CPLUSPLUS_HUMAN_H
