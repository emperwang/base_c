//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_ASSERT_DEMO_H
#define CPLUSPLUS_ASSERT_DEMO_H

#include <iostream>


/*
 *  assert 断言, 是宏而非函数. 作用是如果它的条件返回错误,则终止程序执行
 *  可以通过定义DEBUG 来关闭assert, 但需要在源代码的开头, include<assert.h> 之前
 */
namespace test_assert{

    void test_assert();

    void test_ignore_assert();
}


#endif //CPLUSPLUS_ASSERT_DEMO_H
