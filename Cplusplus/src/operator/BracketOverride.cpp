//
// Created by Sparks on 2021/8/27.
//
#include "operator.h"

void bracketoverrid::test_salary_manager_function() {
    bracketoverrid::SalaryManage s(3);
    s["zhangsan"] = 2088.0;
    s["wangwu"] = 12088.0;
    s["zhaoliu"] = 42088.0;

    // 中括号使用
    std::cout<<"zhangsan " << s["zhangsan"] <<std::endl;
    std::cout<<"wangwu " << s["wangwu"] <<std::endl;
    std::cout<<"zhaoliu " << s["zhaoliu"] <<std::endl;
    std::cout<<"zhouqi " << s["zhouqi"] <<std::endl;

    std::cout << "--------------------------------------------display----------------------"<<std::endl;

    s.display();
}

clockoper::Clock::Clock(int h, int m, int s) {
    if ((h >=0 && h<24) && (m>=0 && m<60) &&(s>=0 && s<60)){
        Hour = h;
        Minute = m;
        Second = s;
    }else{
        std::cout << "输入时间格式有误."<<std::endl;
    }
}

void clockoper::Clock::ShowTime() {
    std::cout<< Hour<<":"<<this->Minute<<":"<<this->Second<<std::endl;
}

// 时间递增一秒(重载前缀++运算符)
class clockoper::Clock& clockoper::Clock::operator++() {
    Second++;
    if (Second >= 60){
        Second = Second - 60;
        Minute++;
        if (Minute >= 60){
            Minute = Minute - 60;
            Hour++;
            Hour = Hour % 24;
        }
    }
}
// 时间递增
class clockoper::Clock clockoper::Clock::operator++(int ) {
    Clock old  = *this;
    ++(*this);
    return old;
}

void clockoper::test_clock_function(){
    clockoper::Clock myClock(23,59,59);
    std::cout << "display initial time: "<<std::endl;
    myClock.ShowTime();

    std::cout <<"执行myClock++后的时间为: "<<std::endl;
    (myClock++).ShowTime();

    std::cout<<"执行++myClock后的时间" <<std::endl;
    (++myClock).ShowTime();
    //system("pause");
}

void clockoper::test_convert_function(){
    Circle c(2.3, 3.4, 2.5);
    int r = c;  // 调用 operator int() 将circle转换成int

    double length = c; // 调用operator double, 转换成double
    float area = c; // 调用operator float, 将circle 类型准换成float

    double len = (double)c; // 桩circle类型强制转换成double
}


void clockoper::test_parentheses_function(){
    Time t1(12,10,11);
    t1.showTime();
    t1.operator()(23, 20,23);
    t1.showTime();
    t1(10,10,10);
    t1.showTime();
}
