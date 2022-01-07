//
// Created by Sparks on 2021/9/8.
//
#include "encapsulation.h"
void encapsulation::test_extend_function(){
    std::cout << "请输入工作周: " <<std::endl;
    int week;
    std::cin>>week;
    Manager m("小王","111111", week);
    m.display();

    std::cout <<"请输入销售利润: "<<std::endl;
    int profit;
    std::cin >> profit;
    std::cout<<"请输入销售件数: "<<std::endl;
    int x;
    std::cin>>x;
    SaleWorker s("小李","22222", profit, x);
    s.display();


    std::cout << "请输入工作小时:"<<std::endl;
    int hour;
    std::cin >> hour;
    HourWorker h("小何", "333333",hour);
    h.display();
}


