//
// Created by Sparks on 2021/9/8.
//

#ifndef CPLUSPLUS_FILE_H
#define CPLUSPLUS_FILE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

namespace file_handle{
    class Person {
    private:
        char Name[20];
        char Id[20];
        int Math;
        int Chinese;
        int English;
        int Sum;

    public:
        Person(){}
        Person(char*name, char*id, int math, int chinese, int english):Math(math),Chinese(chinese),English(english){
            strcpy(Name, name);
            strcpy(Id, id);
            this->Sum = this->Math + this->English + this->Chinese;
        }

        void display(){
            std::cout << Name << "\t" <<Id <<"\t"<<Math << "\t"<<Chinese<<"\t"<<Sum<< std::endl;
        }
    };

    void test_file_write_function();
}


#endif //CPLUSPLUS_FILE_H
