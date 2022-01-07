//
// Created by Sparks on 2021/8/24.
//
#include <iostream>

extern "C" {
    #include "add.h"
}

/*
 * gcc -c add.c
 * g++ add.cpp add.o -o main
 */
int main(){
    int a = add(100,200);
    printf("cpp call c func: %d\n", a);
}
