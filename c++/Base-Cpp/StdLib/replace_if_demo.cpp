#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
replace_if
����:
�������ڷ���������Ԫ��,�滻����Ԫ��

����ԭ��:
replace_if(beg, end, _pred, nrewValue);
*/

void replace_if_print_fun(int val) {
	cout << val << " ";
}

class replace_if_compare {
public:
	bool operator()(int val) {
		return val > 30;
	}
};

// �滻����30��ֵ
void test_replace_if() {
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(70);
	v.push_back(20);
	v.push_back(90);

	replace_if(v.begin(), v.end(), replace_if_compare(), 20000);

	for_each(v.begin(), v.end(), replace_if_print_fun);
	cout << endl;
}

//int main() {
//	test_replace_if();
//
//
//
//	system("pause");
//	return 0;
//}