#include <iostream>
#include <string>
#include <stdarg.h>
#include <malloc.h>
using namespace std;

void testSwitch() {
	int did;
	int count = 5;
	while (count-- > 0) {
		cout << "Ա�������: " << endl;
		cout << "1. Ա��" << endl;
		cout << "2. ����" << endl;
		cout << "3. �ϰ�" << endl;
		cin >> did;
		switch (did) {
		case 1:
			cout << "input value : " << did << endl;
			break;
		case 2:
			cout << "input value : " << did << endl;
			break;
		case 3:
			cout << "input value : " << did << endl;
			break;
		default:
			cout << "������Ч��ѡ��." << endl;
			continue;
			break;
		}
		cout << "find output .. " << endl;
	}
}

// �������

void printList(const char *format, ...) {
	va_list ap;
	va_start(ap, format);
	// ����һ�����飬���ڴ洢�ַ���
	char *buf = (char *)malloc(1024);
	
	if (buf) {
		cout << "formating..." << endl;
		vsnprintf(buf ,1024, format, ap);
		// free(buf);
		va_end(ap);
	}
	string result = buf;
	cout << "format result : " << result << endl;
	free(buf);
}

int main() {

	string aa = "hello";
	string bb = "hello";
	/*bool flag = (aa == bb);
	cout << flag << endl;
	cout << aa.compare(bb) << endl;
	int a;
	cin >> dec >> a;
	cout << "int val: " <<(int) a << endl;*/
	
	// testSwitch();

	printList("str: %s, str1: %s, str2: %s", "first", "second", "third");

	system("pause");
	return 0;
}