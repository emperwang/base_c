//
// Created by Sparks on 2021/9/1.
//
#include "container.h"

void test_map_function1(){

    std::map<const char*,const char*> mps;

    std::map<const char*, const char*>::iterator iter;

    const char key[3][20]= {"img", "system","ip"};
    const char value[3][20] = {"d:/a.img","win7","192.168.6.3"};

    // map_pair 插入
    for (int i = 0; i < 2; ++i) {
        mps.insert(std::make_pair(key[i], value[i]));
    }
    // paire<const char*, const char*> 插入
    mps.insert(std::pair<const char*, const char*>(key[2], value[2]));
    // 数组方式插入
    mps["addr"] = "china";

    //迭代器获取元素
    for (iter = mps.begin(); iter != mps.end(); iter++){
        std::cout << iter->first <<"\t"<<iter->second << std::endl;
    }

    char key1[20];

    std::cout<<"please input key for find" <<std::endl;
    std::cin.getline(key1,20);
    // 查找元素
    for (iter = mps.begin(); iter != mps.end(); iter++){
        if (strcmp(iter->first, key1) == 0){
            std::cout << iter->first<<" find it."<<", value = "<<iter->second<<std::endl;
        }
    }

    // 第一种删除方式
    // find职能用于查找数组建立的形式,并且不支持输入
    iter = mps.find("addr");
    if (iter != mps.end()){
        std::cout << iter->first << "按照key查找出来了," << "对应的value为:"<< iter->second<<std::endl;
        std::cout << "开始删除元素" <<std::endl;
        mps.erase(iter);
    }

    // 第二种删除方式
    // 按照key删除元素
    char drop_key[20];
    // 按照value 删除元素
    char drop_value[20];
    std::cout <<"请输入key: "<<std::endl;
    std::cin.getline(drop_key,20);
    std::cout << "请输入value: "<<std::endl;
    std::cin.getline(drop_value,20);
    // 循环取出元素
    for(iter= mps.begin(); iter != mps.end(); iter++){
        if (strcmp(iter->first, drop_key) == 0){
            std::cout << iter->first<<"按照key查找出来." << "对应的value为:"<<iter->second<<std::endl;
            std::cout << "开始删除元素."<<std::endl;
            mps.erase(iter);
            break;
        }

        if(strcmp(iter->second,drop_value) == 0){
            std::cout << iter->second<<"value 查找出来了. "<< "对应的key为:"<<iter->first<<std::endl;
            std::cout << "开始删除元素.."<<std::endl;
            break;
        }
    }
    std::cout << "删除元素以后...."<<std::endl;
    //循环取出元素
    for(iter= mps.begin(); iter != mps.end(); iter++){
        std::cout <<iter->first<<"\t" << iter->second<<std::endl;
    }
}


