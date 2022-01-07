//
// Created by Sparks on 2021/8/24.
//
extern int add(int ,int);

#include <stdio.h>
/*
 * g++ -c add.cpp
 * gcc c_call_cpp.c add.o -o main
 */
void main(){
    int b = add(3,5);
    printf("c call cpp func: %d \n", b);
};

