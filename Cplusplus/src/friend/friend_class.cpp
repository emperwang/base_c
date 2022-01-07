//
// Created by Sparks on 2021/8/24.
//


#include "friend.h"

using namespace friend_class;
void friend_class::test_friend_class(){
    A a(500);
    B b;
    int num = b.getNum(a);
    std::cout << "friend class get num: " <<num << std::endl;
}
