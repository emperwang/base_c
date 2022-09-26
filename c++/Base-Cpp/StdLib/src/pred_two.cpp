#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <algorithm>
// 使用函数对象改变sort的默认排序策略
class m_pred_compare {
public:
	bool operator()(int val1, int val2) {
		return  val1 > val2;
	}
};

// 使用自定义 函数对象  改变容器的排序策略
void test_pred_two() {
	vector<int> v1;
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(10);
	v1.push_back(50);
	v1.push_back(40);
	sort(v1.begin(), v1.end());
	cout << "默认排序: " << endl;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	// 函数对象修改排序策略
	sort(v1.begin(), v1.end(), m_pred_compare());
	cout << "自定义排序策略: " << endl;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


//int main() {
//	test_pred_two();
//
//
//	system("pause");
//	return 0;
//}