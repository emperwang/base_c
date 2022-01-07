#include <iostream>
#include <string>
using namespace std;

/*
string 的构造函数
string()
string(const char *)
string(const string &str)
string(int n, char c)
*/
void testConstruct() {
	const char *s = "hello world";
	
	string s1(s);

	cout << "s1 = " << s1 << endl;
	
	// 拷贝构造函数
	string s2(s1);
	cout << "s2 = " << s2 << endl;

	// n 个ele 初始化
	string s3(10, 'b');
	cout << "s3 = " << s3 << endl;

}


/*
赋值操作
string& operator=(const char*s)
string&	operator=(const string s)
string& operator=(char c)
string&	assign(const char *s)
string&	assign(const char *s, int n)		// 把s的前n个字符赋值
string&	assign(const string &s)
string&	assign(int n, char c)
*/

void assign() {
	const char *s = "hello c++";
	string s1 = s;
	cout << "s1 = " << s1 << endl;

	string s2 = s1;
	cout << "s2 = " << s2 << endl;

	string s3;
	s3 = 'a';
	cout << "s3 = " << s3 << endl;

	string s4;
	s4.assign(s);
	cout << "s4 = " << s4 << endl;

	string s5;
	s5.assign(s, 2);
	cout << "s5 = " << s5 << endl;

	string s6;
	s6.assign(s1);
	cout << "s6 = " << s6 << endl;

	string s7;
	s7.assign(10, 'c');
	cout << "s7 = " << s7 << endl;
}

/*
字符串拼接:
string&	operator+=(const char* s); 
string&	operator+=(const char c)
string&	operator+=(const string& str)
string&	append(const char *s)
string&	append(const char *s, int n);		// 把字符串s的前n个字符连接到当前字符串结尾
string&	append(const string &s)				
string&	append(const string &s, int pos, int n)	// 字符串s中从pos开始的n个字符连接到字符串结尾
*/

void testAppend() {
	string s1 = "I ";
	s1 += "love play game";
	cout << "s1 = " << s1 << endl;

	s1 += 'C';
	cout << "s1= " << s1 << endl;

	string s2 = " LOL  DNF ";
	s1 += s2;
	cout << "s1= " << s1 << endl;


	string s3;
	const char *s = "I PLAY GAME";
	s3.append(s);
	cout << "s3 = " << s3 << endl;
	
	//s3.append(s2);
	//cout << "s3 = " << s3 << endl;

	//s3.append(s2, 4);
	//cout << "s3 = " << s3 << endl;
	
	s3.append(s2, 5,4);
	cout << "s3 = " << s3 << endl;
}
/*
字符串查找
int find(const string& str, int pos = 0) const;	// 查找str第一次出现位置，从pos开始查找
int find(const char *s, int pos=0) const;		// 查找s第一次出现位置， 从pos开始查找
int find(const char*s, int pos, int n) const;	// 从pos开始查找s的前n个字符第一次出现位置
int find(const char c, int pos=0) const;		// 查找字符c第一次出现位置
int rfind(const string& str, int pos=npos) const;// 查找str最后一次位置  从pos开始查找
int rfind(const char* s, int pos=npos) const;	// 查找s最后一次位置，从pos开始查找
int rfind(const char *s, int pos, int n) const;	//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos=0) const;		// 查找字符c最后一次出现位置

string& replace(int pos, int n, const string& str);	// 替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char *s);		// 替换从pos开始的n个字符串为字符串s
*/


/*
字符串比较操作
>0	大于
=0	相等
<0	小于
int compare(const string &s)
int compare(const char *s);
*/

/*
string中的字符获取功能
char& operator[](int n)
char& at(int n)
*/

/*
字符串的插入和删除
string& insert(int pos, const char *s)		// 在指定位置插入 s
string&	insert(int pos, const string& str);	// 在指定位置插入字符串 str
string&	insert(int pos, int n, char c)		// 在指定位置插入n个字符c
string& erase(int pos, int n=npos);			// 删除从pos开始的前n个字符
*/

/*
string 字串

string substring(int pos=0, int n= npos);	// 返回由pos开始的n个字符组成的字符串
*/

//int main() {
//
//	//testConstruct();
//	//assign();
//	testAppend();
//	system("pause");
//	return 0;
//}