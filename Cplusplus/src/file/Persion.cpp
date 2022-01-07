//
// Created by Sparks on 2021/9/8.
//
#include "FileHeader.h"

void file_handle::test_file_write_function(){
    char ch;
    char Name[20], Id[20];
    int Math, Chinese, English;
    std::fstream ioFile;
    ioFile.open("E:\\code-workSpace\\project-C\\base-C\\Cplusplus\\person.dat", std::ios::out | std::ios::app);

    std::cout << "----------------建立学生档案信息----------------------\n";
    do {
        std::cout << "请输入姓名: \n";
        std::cin >> Name;

        std::cout << "请输入身份证号: \n";
        std::cin >> Id;

        std::cout <<"请输入数学成绩 : \n";
        std::cin >> Math;

        std::cout << "请输入汉语成绩 :\n";
        std::cin >> Chinese;

        std::cout << "请输入英语成绩:\n";
        std::cin >> English;

        Person per(Name, Id,Math, Chinese, English);
        ioFile.write((char*)&per, sizeof(per));
        std::cout <<"是否继续建档?(y/Y) :\n";
        std::cin >> ch;

    }while (ch == 'y' || ch == 'Y');

    ioFile.close();
    ioFile.open("E:\\code-workSpace\\project-C\\base-C\\Cplusplus\\per.dat", std::ios::in);
    Person p;

    ioFile.read((char*)&p, sizeof(p));
    std::vector<Person> v;
    std::vector<Person>::iterator vt;
    /*while(!ioFile.eof()){
        v.push_back(p);
        ioFile.read((char*)&p, sizeof(p));
    }*/

    ioFile.close();
    std::cout <<"---------输出档案信息---------"<<std::endl;
    for(vt = v.begin(); vt!= v.end(); vt++){
        (*vt).display();
    }
}



