#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <numeric>


/*
fill
����:
������ָ��������ֵ

����ԭ��:
fill(beg, end, value)

value: Ҫ����ֵ
*/
void fill_print(int va) {
	cout << va << " ";
}

void test_fill(){
	vector<int> v;
	v.resize(10);

	fill(v.begin(), v.end(), 1000);
	for_each(v.begin(), v.end(), fill_print);
	cout << endl;
}


//int main() {
//	test_fill();
//
//
//	system("pause");
//	return 0;
//}