//
// Created by Sparks on 2021/8/24.
//

#include "friend.h"

int friend_func::getANum(friend_func::A &ca) {
    return ca.num;
}

void friend_func::test_friend_func(){
    friend_func::A a(100);

    int re = friend_func::getANum(a);
    std::cout<<"friend func get num : "<<re << std::endl;
}


