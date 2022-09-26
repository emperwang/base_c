#include <iostream>
#include <list>

using namespace std;

/*
���캯��
list<T> list;
list(begin, end)
list(n ,ele)
list(const list &list)
*/

/*
��ֵ�ͽ���
assign(begin, end)
assign(n, ele)
list& operator=(const list &lst)
swap(list)
*/

/*
��С����
size()
empty()
resize(num)
resize(num, ele)
*/


/*
�����ɾ��
push_back(ele)		// β��Ԫ��
pop_back()			// βɾԪ��
push_front(ele)		// ͷ��Ԫ��
pop_front()			// ͷɾԪ��

insert(pos, ele)	// ��posλ�ò���eleԪ�صĿ���
insert(pos, n, ele)	// ��posλ�ò���n��eleԪ��
insert(pos, begin, end)	// ��posλ�ò���[begin,end)����Ԫ��

clear()		// �������

erase(begin, end)	// ɾ�� [begin, end) �����Ԫ�أ� ������һ�����ݵ�λ��
erase(pos)			// ɾ��posλ�õ�Ԫ��	������һ��Ԫ�ص�λ��
remove(ele)		// ɾ��������������eleƥ���Ԫ��

*/

/*
���ݴ�ȡ
front()		// ���ص�һ��Ԫ��
back()		// �������һ��Ԫ��

*/

/*
��ת������
reverse()		// ��ת����
sort()			// ��������

*/

void printList(list<int> &li) {
	for (list<int>::iterator it = li.begin(); it != li.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// �Զ�������ʽ
bool  myCompare(int a, int b) {
	return a > b;
}

void testSort() {
	list<int> li;
	for (int i = 0; i < 10; i++) {
		int tmp =  rand() % 40 + 60;
		li.push_back(tmp);
	}
	cout << "��תǰ : " << endl;
	printList(li);

	li.reverse();
	cout << " ��ת�� : " << endl;
	printList(li);

	li.reverse();
	cout << "����ǰ :" << endl;
	printList(li);

	cout << "�����: " << endl;
	//li.sort();
	li.sort(myCompare);
	printList(li);
}

//int main() {
//	testSort();
//
//
//	system("pause");
//	return 0;
//}