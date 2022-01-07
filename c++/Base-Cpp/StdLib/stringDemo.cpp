#include <iostream>
#include <string>
using namespace std;

/*
string �Ĺ��캯��
string()
string(const char *)
string(const string &str)
string(int n, char c)
*/
void testConstruct() {
	const char *s = "hello world";
	
	string s1(s);

	cout << "s1 = " << s1 << endl;
	
	// �������캯��
	string s2(s1);
	cout << "s2 = " << s2 << endl;

	// n ��ele ��ʼ��
	string s3(10, 'b');
	cout << "s3 = " << s3 << endl;

}


/*
��ֵ����
string& operator=(const char*s)
string&	operator=(const string s)
string& operator=(char c)
string&	assign(const char *s)
string&	assign(const char *s, int n)		// ��s��ǰn���ַ���ֵ
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
�ַ���ƴ��:
string&	operator+=(const char* s); 
string&	operator+=(const char c)
string&	operator+=(const string& str)
string&	append(const char *s)
string&	append(const char *s, int n);		// ���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string&	append(const string &s)				
string&	append(const string &s, int pos, int n)	// �ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
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
�ַ�������
int find(const string& str, int pos = 0) const;	// ����str��һ�γ���λ�ã���pos��ʼ����
int find(const char *s, int pos=0) const;		// ����s��һ�γ���λ�ã� ��pos��ʼ����
int find(const char*s, int pos, int n) const;	// ��pos��ʼ����s��ǰn���ַ���һ�γ���λ��
int find(const char c, int pos=0) const;		// �����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos=npos) const;// ����str���һ��λ��  ��pos��ʼ����
int rfind(const char* s, int pos=npos) const;	// ����s���һ��λ�ã���pos��ʼ����
int rfind(const char *s, int pos, int n) const;	//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos=0) const;		// �����ַ�c���һ�γ���λ��

string& replace(int pos, int n, const string& str);	// �滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char *s);		// �滻��pos��ʼ��n���ַ���Ϊ�ַ���s
*/


/*
�ַ����Ƚϲ���
>0	����
=0	���
<0	С��
int compare(const string &s)
int compare(const char *s);
*/

/*
string�е��ַ���ȡ����
char& operator[](int n)
char& at(int n)
*/

/*
�ַ����Ĳ����ɾ��
string& insert(int pos, const char *s)		// ��ָ��λ�ò��� s
string&	insert(int pos, const string& str);	// ��ָ��λ�ò����ַ��� str
string&	insert(int pos, int n, char c)		// ��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n=npos);			// ɾ����pos��ʼ��ǰn���ַ�
*/

/*
string �ִ�

string substring(int pos=0, int n= npos);	// ������pos��ʼ��n���ַ���ɵ��ַ���
*/

//int main() {
//
//	//testConstruct();
//	//assign();
//	testAppend();
//	system("pause");
//	return 0;
//}