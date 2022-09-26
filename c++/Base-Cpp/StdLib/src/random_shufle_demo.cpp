#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

/*
函数原形:
random_shuffle(beg, end)
对指定范围内的元素随机调整次序
*/

void test_random_shuffle() {
	// 时间时间作为随机种子
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	random_shuffle(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


//int main() {
//	test_random_shuffle();
//	system("pause");
//	return 0;
//}