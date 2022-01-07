//
// Created by Sparks on 2021/8/24.
//
#include "Assert_demo.h"
# define NDEBUG // 忽略断言
#include <cassert>

void test_assert::test_ignore_assert(){
    int x = 7;
    x = 8;
    assert(x == 7);
}

