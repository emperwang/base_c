#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// transform  �㷨
/*
����:
����������ͬһ��������

����ԭ��:
transform(iterator begin1, iterator end1, iterator begin2, _func)
beign1: Դ������ʼ������ 
end1: Դ��������������
beign2:	Ŀ��������ʼ������
_func: �������ߺ�������

*/

class mTransform {
public :
	int operator()(int val) {
		//return val;
		return val + 100;
	}
};

class mprint {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void testTransform() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	vector<int> target;
	target.resize(v.size()); // ע��: Ŀ��������Ҫ�ȿ��ٿռ�,��Ȼ��ʧ��
	transform(v.begin(), v.end(), target.begin(), mTransform());

	for_each(target.begin(), target.end(), mprint());
	cout << endl;
}

//int main() {
//	testTransform();
//
//	system("pause");
//	return 0;
//}