#include <iostream>
#include <deque>

using namespace std;

/*
���캯��:

deque<T> deq;
deque(begin, end);	// ���������乹��
deque(n, ele);		// n��Ԫ�صĹ�����
deque(const deque &deq);	// �������캯��
*/


/*
��ֵ����
deque& operator=(const deque &deq);// ���������  =
void assign(begin, end);	// ���丳ֵ
void assign(m,ele)			// n��Ԫ�ظ�ֵ
*/

/*
empty()		// �ж��Ƿ�Ϊ��
size()		// Ԫ�ظ���
resize(size)	// �������ô�С
resize(size, ele)	// �������ô�С����ָ���ռ����ʱ��Ĭ��ֵ���ֵΪele
*/


/*
�����ɾ������
push_back(ele)		// β�巨
push_front(ele)		// ͷ�巨
pop_back()			// βɾ��
pop_front()			// ͷɾ��

insert(pos, ele)		// ��posλ�ò���һ��Ԫ��
insert(pos, n, ele)		// ��posλ�ò���n��Ԫ��ele
insert(pos, beg, end)	// ��posλ�ò��� [beg�� end)�����Ԫ��
clear()					// �������
erase(beg, end)			// ɾ��[beg, end) ���������  ������һ��Ԫ�ص�λ��
erase(pos)				// ɾ��posλ�õ�Ԫ�أ� ������һ��Ԫ�ص�λ��
*/

/*
���ݴ�ȡ:
at(int idx)			// ����idxλ�õ�Ԫ��
operator[](int idx)	// ��������λ�õ�Ԫ��
front()				// ��ȡͷԪ��
back()				// ��ȡβԪ��
*/

/*
�������

sort(iterator beg, iterator end)		// ��beg �� end�����Ԫ�ؽ�������

*/
