#include <iostream>
#include <string>
using namespace std;

// �����ʹ��
void testPair() {
	pair<string, int> pr(string("zhangsan"), 50);
	cout << "name: " << pr.first << ", age = " << pr.second << endl;

	pair<string, int> pt = make_pair(string("wangwu"), 90);
	cout << "name : = " << pt.first << " , age = " << pt.second << endl;
}
//int main() {
//	testPair();
//
//	system("pause");
//	return 0;
//}