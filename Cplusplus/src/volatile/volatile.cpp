//
// Created by Sparks on 2021/8/24.
//
#include "volatile.h"

void volatile_name::test_modify_volatile_val(){
    const volatile int local = 10;
    int *ptr = (int*)&local;
    printf("Initial value of volatile local: %d \n", local);

    *ptr = 100;
    printf("Modified value of volatile local: %d\n", local);
}

void volatile_name::test_modify_no_volatile_val(){
    const int local = 10;
    int *ptr = (int*)&local;

    printf("Initial value of local: %d \n", local);

    *ptr = 100;
    printf("Modified value of local: %d\n", local);
}

