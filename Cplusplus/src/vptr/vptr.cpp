//
// Created by Sparks on 2021/8/22.
//
#include "vptr.h"

vptrFun getAddr(void* obj, int offset){
    std::cout << "========================" <<std::endl;
    // 64位操作系统, 占8字节,通过 *(unsigned long *)obj 取出前8字节，即vptr指针
    void * vptr_addr = (void *)*(unsigned long*)obj;

    /*
     * 通过vptr指针访问virtual table,因为虚表中每个元素(虚函数指针)在64位编译器下是8个字节,因此通过
     * *(unsigned long*) vptr_addr 取出前8字节
     * 后面加上偏移量就是每个函数的地址
     */
    void* fun_addr = (void *)*((unsigned long*)vptr_addr+offset);
    printf("func_addr: %p\n", fun_addr);
    return (vptrFun)fun_addr;
}

void test_vptr_table(){
    vptr_base base;
    vptr_impl impl;

    // 基类指针指向派生类实例
    vptr_base *pt = new vptr_impl();
    // 基类引用指向 基类实例
    vptr_base &pp = base;
    // 基类引用指向 派生类实例
    vptr_base &pd = impl;

    std::cout << "基类对象直接调用 "<<std::endl;
    base.func1();
    base.fun2();

    std::cout << "基类引用调用 "<<std::endl;
    pp.func1();
    pp.fun2();

    std::cout << "基类指针指向派生类 调用" <<std::endl;
    pt->func1();
    pt->fun2();

    std::cout << "基类引用指向 派生类的调用" <<std::endl;
    pd.fun2();
    pd.func1();

    // 手动查找vptr 和 vtable
    std::cout << "手动查找 vtable "<<std::endl;
    vptrFun  f1 = getAddr(pt, 0);
    (*f1)();
    vptrFun  f2 = getAddr(pt, 1);
    (*f2)();
    delete pt;
}

