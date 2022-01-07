//
// Created by Sparks on 2021/9/1.
//
#include "template.h"

template<typename T, int MAXSIZE> void template_ns::Stack<T,MAXSIZE>::push(T e) {
    if (!isFull()){
        this->elems[++top] = e;
    }else{
        std::cout<<"stack full" << std::endl;
    }
}


template <typename T, int MAXSIZE> T template_ns::Stack<T,MAXSIZE>::pop() {
    if (!isEmpty()){
        return this->elems[top--];
    }

    std::cout<<"empty stack" << std::endl;
    return 0;
}


void template_ns::test_template_class_function(){
    template_ns::Stack<int, 10>s1;
    s1.init();
    int i;
    for (i =0; i< 10;i++){
        s1.push(i);
    }

    for (int j = 0; j <10; ++j) {
        std::cout<< "stack pop: "<< s1.pop()<<std::endl;
    }
}

template<typename T> T& template_ns::Array<T>::operator[](int i) {
    if (i < 0 || i > MAXNUM){
        std::cout << "index output bound..."<<std::endl;
    }
    return array[i];
}

template<typename T> void template_ns::Array<T>::Sort() {
    std::cout << "template sort" << std::endl;
    int p;
    for (int i = 0; i < MAXNUM; ++i) {
        p = i;
        for (int k = i+1; k < MAXNUM; ++k) {
            if(array[p] < array[k]){
                p = k;
            }
        }
        T t = array[i];
        array[i] = array[p];
        array[p] = t;
    }
}

template<> void template_ns::Array<char *>::Sort() {
    std::cout << "char* sort" << std::endl;
    int p;
    for (int i = 0; i < MAXNUM; ++i) {
        p = i;
        for (int k = i+1; k < MAXNUM; ++k) {
            if(strcmp(array[p],array[k]) < 0){
                p = k;
            }
        }
        char* t = array[i];
        array[i] = array[p];
        array[p] = t;
    }
}

void template_ns::test_partial_spec_function(){
    Array<int> a1;
    a1[0] = 1;
    a1[1] = 23;
    a1[2] = 6;
    a1[3] = 3;
    a1[4] = 9;
    a1.Sort();
    for (int i = 0; i < 5; ++i) {
        std::cout << "i = "<< i<<", value: "<<a1[i]<<std::endl;
    }

    Array<char*> b1;
    b1[1] ="x1";
    b1[2] ="ya";
    b1[3] ="ad";
    b1[4] ="be";
    b1[5] ="bc";
    for (int j = 0; j <5; ++j) {
        std::cout << "index = " <<j<<", values "<<b1[j]<<std::endl;
    }
}

