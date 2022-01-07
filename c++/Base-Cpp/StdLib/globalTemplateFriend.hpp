#ifndef __GLOBALTEMPLATEFRIEND_H__
#define __GLOBALTEMPLATEFRIEND_H__
#include <string>
using namespace std;
template<class T1, class T2>
class Person;

// ��������������Ϊ�Ǵ�ӡPerson�࣬����Ҫ��ǰ����Person��
template<class T1, class T2>
void printPerson2(Person<T1, T2> p);

// template<typename T1, typename T2>
template<class T1, class T2>
class Person {

	// ��Ԫ��������ʵ��
	friend void printPerson(Person<T1,T2> p) {
		cout << "name = " << p.m_name
			<< "\t age = " << p.m_age << endl;
	}

	// ��Ԫ��������ʵ��
	// ע��˴��� <> ��ʾ�˺�����һ��ģ�庯��
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

// ������ʵ��
template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
	cout << "printPerson2"
		<< "\t name = " << p.m_name
		<< "\t age = " << p.m_age << endl;
}


#endif