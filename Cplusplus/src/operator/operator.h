//
// Created by Sparks on 2021/8/27.
//

#ifndef CPLUSPLUS_OPERATOR_H
#define CPLUSPLUS_OPERATOR_H

#include <iostream>
#include <cstring>
namespace bracketoverrid{
    // 员工信息基本结构
    struct Person{
        double salary;
        char *name;
    };

    class SalaryManage{
    private:
        Person *employ; // 存放员工信息的数组
        int max;    // 数组下标下界
        int n;  // 数组中的实际职工数

    public:
        SalaryManage(int Max=0):max(Max),n(0){
            employ = new Person[max];
        }

        // 中括号重载
        // 返回引用 特性是可以直接放在左值,直接使用
        double &operator[](char *name) {
            Person *p;
            for(p = employ; p<employ+n; p++){
                if(strcmp(p->name, name)== 0){
                    return p->salary;
                }
            }
            // 不存在
            p = employ+ n++;
            p->name = new char[strlen(name)+1];
            strcpy(p->name, name);
            p->salary = 0;
            return p->salary;
        }

        void display (){
            for (int i = 0; i < n; ++i) {
                std::cout <<employ[i].name << "   " << employ[i].salary <<std::endl;
            }
        }

        ~SalaryManage(){
            delete [] employ;
        }
    };

    void test_salary_manager_function();
}


namespace clockoper{
    class Clock{
        private:
            int Hour, Minute, Second;

        public:
            Clock(int h=0, int m=0, int s=0);

            void ShowTime();

            // 前缀++运算符重载
            Clock &operator++();

            // 后缀++运算符重载
            Clock operator++(int);

            ~Clock(){
                std::cout <<"Clock deconstructor .. " <<std::endl;
            }
    };

    void test_clock_function();

    /*
     * 运算符重载之 强制转换
     * 有一个类Circle,设计该类的类型转换函数,当将Circle对象转换成int类型时,
     * 返回圆的半径; 当将它转换成double时,就返回圆的周长;
     * 当将它转换成 float时,就返回圆的面积
     *
     * 类型转换函数没有参数
     * 类型转换函数没有返回类型
     * 类型转换含糊必须返回将要转换成的type类型数据
     */
    class Circle{
    private:
        double x,y,r;

    public:
        Circle(double x1, double y1, double r1):x(x1),y(y1),r(r1){}
        operator int(){
            std::cout << "circle int() function"<<std::endl;
            return int(r);
        }

        operator double(){
            std::cout << "circle double() function"<<std::endl;
            return 2*3.14*r;
        }

        operator float(){
            std::cout << "circle float() function"<<std::endl;
            return (float)3.14 * r* r;
        }
    };

    void test_convert_function();

    // 重载圆括号
    class Time{
    private:
        int hh,mm,ss;

    public:
        Time(int h=0, int m=0,int s=0):hh(h),mm(m),ss(s){}

        void operator()(int h,int m,int s){
            std::cout <<"parentheses function()" <<std::endl;
            this->hh = h;
            this->mm = m;
            this->ss = s;
        }

        void showTime(){
            std::cout << hh <<":"<<mm<<":"<<ss<<std::endl;
        }
    };

    void test_parentheses_function();
}

#endif //CPLUSPLUS_OPERATOR_H
