//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_DEFINEHEADER_H
#define CPLUSPLUS_DEFINEHEADER_H

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

/*
 * # 字符串操作符
 */
#define exp(s) printf("test s is :%s\n",s)
#define exp1(s) printf("test s is:%s\n", #s)
#define exp2(s) #s

/*
 * ## 符号连接操作符
 */
#define expA(s) printf("前缀加上后的字符串: %s\n", gc_##s)   // gc_s 必须存在
#define expB(s) printf("前缀机上后的字符串2 为: %s\n", gc_ ## s)
#define gc_hello1 "I am gc_hello1"

/*
 * \ 续行操作符
 */
#define MAX(a,b)  ((a)>(b)?(a) \
                   :(b) )

void test_define_function();


#endif //CPLUSPLUS_DEFINEHEADER_H
