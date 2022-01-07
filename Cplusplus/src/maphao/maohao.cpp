//
// Created by Sparks on 2021/8/24.
//

#include "maohao.h"

// 全局变量
int mao_haocount = 0;

void maohao::test_func_maohao(){
    // 设置全局变量
    ::mao_haocount = 100;
    using namespace maohao;
    A::count = 200;
    std::cout << "global count : " << ::mao_haocount<< std::endl;
}
