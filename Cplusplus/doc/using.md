## 基本使用
局部与全局using, 具体操作如下:
```c++
#incldue <iostream>
#define isNs1 1
#define isGlocal 1
using namespace std;

void func(){    
    cout << "::func" <<endl;
}
namespace ns1{    
    void func(){
        cout << "ns1::func"<<endl;
    }
}

namespace ns2{    
    #ifdef isNs1
        using ns1::func; // ns1中的函数
    #elif   isGlobal
        using ::func;  // 全局中的函数
    #else
        void func(){
            cout << "other ::func"<<endl;
        }
    #endif
}
```

## 改变访问性
```c++
class Baes{    
public:
    std::size_t size() const{
        return n;
    }
protected:
    std::size_t n;
};

class Derived: private Base{    
    public:
        using Base::size;
    protected:
        using Base::n;
};
```
类Derived私有继承了Base,对于它来说成员变量n和成员函数size都是私有的, 如果使用了using语句, 可以改变
他们的可访问性,如上述例子中,size可以按照public的权限访问, n可以按protected的权限访问.

## 函数重载
在继承过程中,派生类可以覆盖重载函数的0个或多个实例, 一旦定义了一个重载版本, 那么其他的重载版本
都会变为不可见.
如果对于基类的重载函数,我们需要在派生类中修改一个,又要让其他的保持可见,必须要重载所有的版本,
这样十分的繁琐.
```c++
class Base{
    public:
        void f1(){}
        void f1(int n){}
};

class Derived :private Base{
    public:
        using Base::f; 
        void f(int n) override {}
};
```
如上代码,在派生类中使用using声明语句制定一个名字而不是指定形参列表,这样一条基类成员函数的using声明
语句就可以把该函数的所有重载实例添加到派生类的作用域中.此时, 派生类只需要定义其特有的函数就可以了,
无需为继承而来的其他函数重新定义.

## 取代typedef
C 中常用的typedef A B 这样的语法, 将B定义为A类型, 也就是给A类型一个别名B.
对应typedef A B, 使用 using B=A 可以进行同样的操作.
```c++
typedef vector<int> V1;
using V2 = vector<int>;
```