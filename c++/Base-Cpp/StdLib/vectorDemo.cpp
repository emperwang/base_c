#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &it) {
	for (vector<int>::iterator bg = it.begin(); bg != it.end(); bg++) {
		cout << *bg << " ";
	}
	cout << endl;
}


void testAdd() {
	// 默认构造函数
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(10);
	cout << "size = " << v.size() << endl;
	printVector(v);

	// 区间构造函数
	vector<int> v2(v.begin(), v.end());
	printVector(v2);

	// n 个 element 构造方式
	vector<int> v3(10, 20);
	printVector(v3);

	// 拷贝构造
	vector<int> v4 = v;
	printVector(v4);

}

// 测试赋值操作
void testAssign() {
	// 1. 初始化一个vector
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	// = 号 赋值
	vector<int> v2 = v1;
	printVector(v2);

	// assign赋值
	vector<int>  v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);
	// assign  n个element 赋值
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

// vector 容器的容量测试
void testCap() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// 判断是否为空
	if (v.empty()) {
		cout << "v 的元素为空" << endl;
	}
	else {
		cout << "v. 容量非空 : " << v.empty() << endl;

		// 打印容量和元素数量
		cout << "v 的容量为 :" << v.capacity() << endl;
		cout << "v 的元素数量 : " << v.size() << endl;
	}


	// 重新设置大小
	v.resize(12);
	printVector(v);

	v.resize(15, 100);  // resize后，如果比原来大，参数2可以指定填充的数. 不指定的话  默认填充0
	printVector(v);

	v.resize(5);
	printVector(v);


}

// vector 添加删除
/*
push_back(ele)	// 尾插
pop_back();		//	尾删
insert(const_iterator pos, ele);		// 在迭代器指定的位置插入元素
insert(const_iterator pos , int count,ele);	// 在迭代器指定的位置， 插入count个ele
erase(const_iterator pos);		// 删除迭代器指定的位置上的元素
erase(const_iterator start, const_iterator end);	// 删除迭代器区间的元素
clear();		// 清理

*/
void testFix() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
	// 尾部插入
		v.push_back(i);
	}
	printVector(v);

	// 尾部删除
	v.pop_back();
	printVector(v);
	// insert 插入
	v.insert(v.begin(), 100000);
	printVector(v);

	// insert
	v.insert(v.begin(), 2, 20000);
	printVector(v);


	// erase
	v.erase(v.begin());
	printVector(v);

	// erase
	//v.erase(v.begin(), v.end());
	
	v.clear();
	printVector(v);
}


// vector 容器的元素获取
void testGet() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}


	// 中括号获取容器的元素值
	cout << "中括号获取元素 []" << endl;
	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << " ";
	}
	cout << endl;

	// at获取元素值
	cout << "at 获取值 " << endl;
	for (int k = 0; k < v.size(); k++) {
		cout << v.at(k) << " ";
	}
	cout << endl;

	cout << "获取第一个元素: " << v.front() << endl;

	cout << "获取最后一个元素:" << v.back() << endl;

}

// vector 空间交换
void testSwap() {
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	cout << "交换前" << endl;
	printVector(v1);
	printVector(v2);

	v1.swap(v2);
	cout << "交换后 : " << endl;
	printVector(v1);
	printVector(v2);


}
// 交换空间的用途
void swapUse() {
	vector<int> v1;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
	}

	// 此时的容量以及大小
	cout << "cap  :" << v1.capacity() << endl;
	cout << "size :" << v1.size() << endl;

	// 重新设置大小后
	// 重新设置大小后，size是3，可以容量是13万，存在很大的空间浪费，故需要进行空间交换
	v1.resize(3);

	// 空间交换
	vector<int>(v1).swap(v1);
	cout << "cap  :" << v1.capacity() << endl;
	cout << "size :" << v1.size() << endl;

}

// 预留空间
void testResover() {

	// 放入10万个数据，可以测试进行了几次空间扩容
	vector<int> v1, v2;
	v2.reserve(100000);
	int num = 0, num1 = 0;
	int *p = NULL, *p2 = NULL;
	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		v2.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			num++;
		}
		if (p2 != &v2[0]) {
			p2 = &v2[0];
			num1++;
		}
	}

	cout << "v1的扩容次数 : " << num << endl;
	cout << "v2的扩容次数 :" << num1 << endl;
}


//int main() {
//	//testAdd();
//	//testAssign();
//	//testCap();
//	//testFix();
//	//testGet();
//	//testSwap();
//	//testSwap();
//	//swapUse();
//	testResover();
//	
//	system("pause");
//	return 0;
//}