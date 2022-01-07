//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_FRIEND_H
#define CPLUSPLUS_FRIEND_H

#include <iostream>

namespace friend_func{
    class A{
    public:
        A(int a):num(a){
            std::cout << " friend_func A construct.."<<std::endl;
        }

        friend int getANum(A &ca);

    private:
        int num;
    };

    int getANum(A &ca);

    void test_friend_func();
}


namespace friend_class{
class A{
public:
    A(int a):num(a){
        std::cout << "friend class construct A"<<std::endl;
    }

    friend class B;

private:
    int num;
};

class B{
public:
    int getNum(A& ca){
        return ca.num;
    }
};

    void test_friend_class();
}


#endif //CPLUSPLUS_FRIEND_H
