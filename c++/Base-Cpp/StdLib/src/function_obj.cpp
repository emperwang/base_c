#include <iostream>
using namespace std;
#include <string>
/*
��������(�º���):
����������ʹ��ʱ, ��������ͨ������������, �����в���,�����з���ֵ
������Ϸ�Ǹ�������ͨ�����ĸ���, ��������������Լ���״̬
�������������Ϊ��������
*/

//����������ʹ��ʱ, ��������ͨ������������, �����в���,�����з���ֵ
class MaddFunc {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

void testPredone() {
	MaddFunc add;
	int ret = add(100, 200);
	cout << "add result : " << ret << endl;
}

// ������Ϸ�Ǹ�������ͨ�����ĸ���, ��������������Լ���״̬
class Mprint {
public:
	Mprint() {
		this->count = 0;
	}

	void operator()(string text) {
		cout << text << endl;
		this->count++;
	}
	// ��¼���� ���ö��ٴ�
	int count;
};

//�������������Ϊ��������
void doPrint(Mprint &p, string text) {
	p(text);
}

void testMPrint() {
	Mprint print;
	print("hello");
	print("hello");
	print("hello");
	print("hello");
	cout << "call times: " << print.count << endl;

	doPrint(print,("this is do print running"));
}


//int main() {
//	//testPredone();
//	testMPrint();
//
//	system("pause");
//	return 0;
//}