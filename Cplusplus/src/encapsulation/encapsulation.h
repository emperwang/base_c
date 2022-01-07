//
// Created by Sparks on 2021/9/8.
//

#ifndef CPLUSPLUS_ENCAPSULATION_H
#define CPLUSPLUS_ENCAPSULATION_H

#include <iostream>
#include <cstring>
namespace encapsulation{
    // 基本类
    class Employee{
    public:
        Employee(const char*name, const char *id){
            strcpy(Name, name);
            strcpy(Id, id);
        }

        char* getName(){
            return Name;
        }

        char *getId(){
            return Id;
        }

        virtual void display(){
            std::cout<<Name << "\t" <<Id<<std::endl;
        }

    private:
        char Name[20];
        char Id[20];
    };

    class Manager:public Employee {
    private:
        int WeeklySalary;

    public:
        // 直接调用构造方法传递, 基类构造方法有参数,派生类必须通过构造方法,在初始化列表中传递参数
        Manager(const char*name, const char*id, int week):Employee(name, id){
            WeeklySalary = week * 1000;
        }

        void display() override {
            std::cout<<"经理 : " <<getName()<<"\t"<<getId()<<"\t"<<WeeklySalary<<std::endl;
        }
    };

    class SaleWorker:public Employee{
    private:
        float baseMoney=800.0;
        float workerMoney;

    public:
        SaleWorker(const char*name, const char*id, int profit, int x):Employee(name, id){
            workerMoney= baseMoney+ x*0.05*profit;
        }

        void display() override {
            std::cout << "销售员: "<<getName()<<"\t" <<getId()<<"\t"<<workerMoney<<std::endl;
        }
    };

    class HourWorker:public Employee{
    private:
        float hourMoney=100.0;
        float TotalMoney;

    public:
        HourWorker(const char*name, const char *id, int i):Employee(name, id){
            TotalMoney = i * hourMoney;
        }

        void display() override {
            std::cout << "小时工: " << getName()<<"\t"<<getId()<<"\t" <<TotalMoney<< std::endl;
        }
    };

    void test_extend_function();
}


#endif //CPLUSPLUS_ENCAPSULATION_H
