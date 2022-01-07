//
// Created by Sparks on 2021/8/24.
//
#include "defineheader.h"

void test_define_function(){
    /*
     * # 字符串操作符
     */
    exp("hello");
    exp1(hello );
    // 或略传入参数的前面和后面的空格
    std::string str = exp2(  bdcp   );
    std::cout << "exp2 string size: " << str.size()<<std::endl;

    // 当传入参数名之间存在空格时,编译器将自动连接各个子字符串
    // 每个子字符串之间用一个空格连接, 忽略剩余空格.
    std::string str2 = exp2(     asdf   edf    );
    std::cout << "str2 size: " << str2.size() <<std::endl;

    // ## operation
    const char* gc_hello = "I am gc_hello";
    expA(hello);
    expB(hello1);

    // \ 操作
    int max = MAX(100,200);
    std::cout << "max value : "<< max <<std::endl;
}
