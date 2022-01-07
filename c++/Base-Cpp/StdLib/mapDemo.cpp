#include <iostream>
#include <map>

using namespace std;


/*
������
map<T1,T2> mp;
map(const map &mp)

��ֵ:
map& operator=(const map &mp)
*/

/*
��С�ͽ���
size()
empty()

swap(st)	// �����������ϵ�����

*/

/*
�����ɾ��
insert(ele)			// ����Ԫ��
clear()				// �������
erase(pos)			// ɾ��pos��������ָ��Ԫ��
erase(begin, end)	// ɾ������[begin,end) ������Ԫ��

erase(key)		// ɾ��������ֵΪkey��Ԫ��

*/

/*
���Һ�ͳ��
find(key)	// ����key�Ƿ����,�����򷵻��������; �����ڷ���  end()
count(key)  // ͳ��key��Ԫ�ظ���

*/

/*
����

*/
// �Զ�������º���
class m_map_sort {
public: 
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};


void test_map_sort() {
	map<int, int> mp;
	mp.insert(make_pair(1, 20));
	mp.insert(make_pair(2, 70));
	mp.insert(make_pair(6, 60));
	mp.insert(make_pair(5, 30));
	mp.insert(make_pair(4, 10));
	mp.insert(make_pair(3, 40));
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		cout << "key : " << it->first << ", val :" << it->second << endl;
	}
	cout << " �Զ������� :" << endl;
	map<int, int, m_map_sort> mp1;
	mp1.insert(make_pair(1, 20));
	mp1.insert(make_pair(2, 70));
	mp1.insert(make_pair(6, 60));
	mp1.insert(make_pair(5, 30));
	mp1.insert(make_pair(4, 10));
	mp1.insert(make_pair(3, 40));
	for (map<int, int, m_map_sort>::iterator it = mp1.begin(); it != mp1.end(); it++) {
		cout << "key : " << it->first << ", val :" << it->second << endl;
	}
}

//int main() {
//	test_map_sort();
//
//	system("pause");
//	return 0;
//}