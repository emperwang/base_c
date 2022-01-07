//
// Created by Sparks on 2021/8/24.
//

#ifndef CPLUSPLUS_UNION_H
#define CPLUSPLUS_UNION_H

/*
 * union 是一种节省空间的特殊类, 一个union可以有多个数据成员,但是在任意时刻只有一个数据成员有值.
 * 当某个成员被赋值后其他成员变为未定义状态. union有一下特定:
 * 1.  默认访问控制符为 public
 * 2. 可以有构造函数, 析构函数
 * 3. 不能含有引用类型的成员
 * 4. 不能继承自其他类, 不能作为基类
 * 5. 不能含有虚函数
 * 6. 匿名 union 在定义所在作用域 可以直接访问union成员
 * 7. 匿名union 不能包含protected 成员或 private 成员
 * 8. 全局匿名联合必须 是静态的
 */
#include <iostream>
// 默认访问控制符为public
union UnionTest{
    // 可以含有构造函数,析构函数
    UnionTest(): i(10){
        std::cout << "UnionTest construct"<<std::endl;
    }
    int i;
private:
    void print(int i) {
        std::cout << i << std::endl;
    }
};

//  全局匿名联合必须是静态的
static union {
    int i;
    double d;
};

void test_union_function();

#endif //CPLUSPLUS_UNION_H
