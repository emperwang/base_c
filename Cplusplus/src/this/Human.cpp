//
// Created by Sparks on 2021/8/20.
//

#include "Human.h"

Human::Human(const char*name, int a, SexType s):age(a),sex(s){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

Human::~Human(){
    delete [] this->name;
}

int Human::get_age() const {
    return this->age;
}

Human& Human::add_age(int a) {
    this->age += a;
    return *this;
}

void test_this_pointer(){
    Human h("wangwu",50,Human::BOY);
    std::cout << "age: "<<h.get_age() << std::endl;

    h = h.add_age(50);
    std::cout << "after add age: " << h.get_age() << std::endl;
}
