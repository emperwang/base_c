#include <iostream>
#include <set>

using namespace std;

/*
���캯��
set<T> s;
set(const set& st)

��ֵ
set& operator=(const set &st);

*/

/*
��С�ͽ���
size()		// ����������Ԫ�صĸ���
empty()		// �ж������Ƿ�Ϊ��
swap(st)	// ����������������

*/

/*
�����ɾ��
insert(ele)		// �������в���Ԫ��
clear()			// �������
erase(pos)		//ɾ��pos��������ָԪ�أ���������һ��Ԫ�صĵ�����
erase(begin, end)	// ɾ�� [begin,end) ������Ԫ�أ�������һ��Ԫ�صĵ�����
erase(ele)			// ɾ��������ֵΪele��Ԫ��
*/

/*
���Һ�ͳ��
find(key)		// ����key�Ƿ���ڣ������ڣ����ش�Ԫ�صĵ������� �����ڣ��򷵻� set.end()
count(key)		// ͳ��key��Ԫ�ظ���
*/


/*
set �� multiset����:
set �����Բ����ظ����ݣ�multiset����
set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
multiset ���������ݣ� ��˿����ظ���������
*/

void testInsert() {
	set<int> st;
	pair<set<int>::iterator, bool> ret = st.insert(10);

	if (ret.second) {
		cout << " ��һ�β���ɹ�" << endl;
	}
	else {
		cout << "��һ�β���ʧ�� " << endl;
	}

	ret = st.insert(10);
	if(ret.second) {
		cout << " ��һ�β���ɹ�" << endl;
	}
	else {
		cout << "��һ�β���ʧ�� " << endl;
	}

	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

}

// �Զ�������º���
class m_compare_Set {
public:
	bool operator()(int v, int v2) {
		return v > v2;
	}
};

void printSet(const set<int> &st) {
	for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// ����set�Զ��������
void testCusSort() {
	set<int> st1;
	st1.insert(10);
	st1.insert(50);
	st1.insert(30);
	st1.insert(40);
	st1.insert(20);
	cout << "Ĭ������ : " << endl;
	printSet(st1);

	set<int, m_compare_Set> st2;
	st2.insert(10);
	st2.insert(50);
	st2.insert(30);
	st2.insert(40);
	st2.insert(20);
	cout << "�Զ������� :" << endl;
	for (set<int, m_compare_Set>::iterator it = st2.begin(); it != st2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//int main() {
//	//testInsert();
//	testCusSort();
//
//	system("pause");
//	return 0;
//}