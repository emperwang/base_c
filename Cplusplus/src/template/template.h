//
// Created by Sparks on 2021/8/30.
//

#ifndef CPLUSPLUS_TEMPLATE_H
#define CPLUSPLUS_TEMPLATE_H

#include <iostream>
#include <cstring>
#define MAXNUM 5

namespace template_ns{
    template <typename T>
    T compareMax(T t1, T t2);

    template <>
    const char* compareMax<const char*>(const char*s1, const char *s2);
    void test_template_function();

    void test_var_array();

    //  类模板
    template<typename T, int MAXSIZE>
    class Stack{
    public:
        Stack(){}

        void init(){top = -1;}

        bool isFull(){
            if (top >= MAXSIZE-1){
                return true;
            }
            return false;
        }

        bool isEmpty(){
            if (top == -1){
                return true;
            }
            return false;
        }

        void push(T e);
        T pop();

    private:
        T elems[MAXSIZE];
        int top;
    };

    void test_template_class_function();


    // 类模板特征化
    template<typename T>
    class Array {
    public:
        Array(){
            for (int i = 0; i < MAXNUM; ++i) {
                array[i] = 0;
            }
        }

        T &operator[](int i);
        void Sort();

    private:
        T array[MAXNUM];
    };

    void test_partial_spec_function();
}


#endif //CPLUSPLUS_TEMPLATE_H
