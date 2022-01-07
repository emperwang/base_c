#ifndef __GLOBALTEMPLATEFRIEND_H__
#define __GLOBALTEMPLATEFRIEND_H__
#include <string>
using namespace std;
template<class T1, class T2>
class Person;

// 函数的声明，因为是打印Person类，所以要提前声明Person类
template<class T1, class T2>
void printPerson2(Person<T1, T2> p);

// template<typename T1, typename T2>
template<class T1, class T2>
class Person {

	// 友元函数类内实现
	friend void printPerson(Person<T1,T2> p) {
		cout << "name = " << p.m_name
			<< "\t age = " << p.m_age << endl;
	}

	// 友元函数类外实现
	// 注意此处的 <> 表示此函数是一个模板函数
	friend void printPerson2<>(Person<T1, T2> p);

public:
	Person(T1 name, T2 age) {
		this->m_name = name;
		this->m_age = age;
	}

	
private:
	T1 m_name;
	T2 m_age;
};

// 函数的实现
template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
	cout << "printPerson2"
		<< "\t name = " << p.m_name
		<< "\t age = " << p.m_age << endl;
}


#endif