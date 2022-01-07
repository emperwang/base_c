#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define MAX 100
/*
һ���򵥵�ͨѶ¼��ʵ��
*/

struct Person {
	string m_Name;
	int age;
	string num;
	int sex;
	string addr;
};

struct PersonNote {
	// �洢�������Ϣ
	struct Person persons[MAX];
	// ��¼����
	int m_Size;
};

void clsScreen() {
	system("pause");
	system("cls");
}

void printItems() {
	cout << "\t*********�绰������***********" << endl;
	cout << "\t***-- 1.����û� *************" << endl;
	cout << "\t***-- 2.��ӡ�û� *************" << endl;
	cout << "\t***-- 3.�����û� *************" << endl;
	cout << "\t***-- 4.�޸��û� *************" << endl;
	cout << "\t***-- 5.ɾ���û� *************" << endl;
	cout << "\t***-- 6.��յ绰��************" << endl;
	cout << "\t***-- 7.�˳�     *************" << endl;
	cout << "\t******************************" << endl;
	cout << endl;

	cout << "����������ѡ��: " << endl;
}

void insert_person(PersonNote *note);
void print_note(PersonNote *note);
void find_person(PersonNote *note);
void update_person(PersonNote *note);
void delete_person(PersonNote *note);
void clear_note(PersonNote *note);
int if_exists(PersonNote *note, string name);
void print_person(Person p);


int main() {
	char select[1024];
	// ����绰��
	PersonNote note;
	note.m_Size = 0;	// ��ʼ����Ϊ0

	while (true)
	{
		begin:
		printItems();
		// ÿ�ζ�ȡ֮ǰ��ն�ȡ�������е�����
		// ����ÿ�ζ�ȡʱ,�ϴ������ֵ�Ͳ�����Ӱ��
		//cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		//cin.clear();
		//cin.getline(select,sizeof(select));
		cin.get(select, sizeof(select));
		//cout << "input val: " << select<<" ,int val: "<< ((int)select[0]) << endl;
		if ( ((int)select[0]) < 49 || ((int)select[0]) > 55) {
			cout << "������������������(1-7)."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
			goto begin;
		}
		switch ((int)select[0]) {
		case 49:		//1.����û�
			insert_person(&note);
			break;
		case 50:		//2.��ӡ�û�
			print_note(&note);
			break;
		case 51:		// 3.�����û�
			find_person(&note);
			break;
		case 52:		// 4.�޸��û�
			update_person(&note);
			break;
		case 53:		// 5.ɾ���û�
			delete_person(&note);
			break;
		case 54:		// 6.��յ绰��
			clear_note(&note);
			break;
		case 55:		// 7. �˳�
			cout << "ллʹ��,�ڴ������´ι���." << endl;
			clsScreen();
			return 0;
		default:
			cout << "switch������������������." << endl;
			clsScreen();
			break;
		}
	}

	clsScreen();
}

void insert_person(PersonNote *note) {
	struct Person p;
	cout << "����������: " << endl;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cin >> p.m_Name;

	cout << "����������: " << endl;
	while (true){
		cin >> p.age;
		if (p.age>0 && p.age < 200){
			break;
		}
		else {
			cout << "�������벻̫��Ŷ������������(1-200)" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
		}
	}

	cout << "�������Ա�:  1 -> ��    2->Ů" << endl;
	
	while (true){
		cin >> p.sex;
		if (p.sex == 1 || p.sex == 2) {
			break;
		}
		else {
			cout << "�Ա����벻̫��Ŷ������������.1 -> ��    2->Ů" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
		}
	}

	cout << "������绰: " << endl;
	cin >> p.num;

	cout << "�������ַ: " << endl;
	cin >> p.addr;

	note->persons[note->m_Size] = p;

	note->m_Size++;

	clsScreen();
}
void print_note(PersonNote *note) {
	if (note->m_Size <= 0) {
		cout << "�绰��Ϊ��..." << endl;
	}
	else {
		int i;
		for (i = 0; i < note->m_Size; i++) {
			print_person(note->persons[i]);
		}
	}

	clsScreen();
}
void print_person(Person p) {
	cout << "����: " << p.m_Name << "\t";
	cout << "����: " << p.age << "\t";
	cout << "�Ա�: " << (p.sex == 1 ? "��" : "Ů") << "\t";
	cout << "�ֻ�: " << p.num << "\t";
	cout << "��ַ: " << p.addr << endl;
}

int if_exists(PersonNote *note, string name) {
	if (note->m_Size <= 0) {
		cout << "ͨѶ¼Ϊ��." << endl;
		return -1;
	}
	int i;
	for (i = 0; i < note->m_Size; i++) {
		if (note->persons[i].m_Name.compare(name) == 0) {
			return i;
		}
	}
	return -1;
}

void find_person(PersonNote *note) {
	if (note->m_Size <= 0) {
		cout << "�绰��Ϊ��..." << endl;
		return;
	}
	string name;
	cout << "������Ҫ��ѯ���û�������: " << endl;
	cin >> name;
	int ret = if_exists(note, name);
	if (ret >= 0) {
		print_person(note->persons[ret]);
	}
	else {
		cout << "�����޴���." << endl;
	}
	clsScreen();
}

void update_person(PersonNote *note) {
	if (note->m_Size <= 0) {
		cout << "�绰��Ϊ��..." << endl;
		return;
	}
	string name;
	cout << "������Ҫ���µ��û�������: " << endl;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cin >> name;
	int ret = if_exists(note, name);
	if (ret >= 0) {
		Person* pp = &note->persons[ret];
		cout << "������Ҫ�޸ĵ�����: " << endl;
		cin >> pp->m_Name;
		
		cout << "������Ҫ�޸ĵ�����: " << endl;
		while (true) {
			cin >> pp->age;
			if (pp->age > 0 && pp->age < 200) {
				break;
			}
			else {
				cout << "��������Ĳ���ȷŶ,����������: (0-200)" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin.clear();
			}
		}

		cout << "������Ҫ�޸ĵ��Ա�: 1 ->  ��,  2 -> Ů " << endl;
		while (true) {
			cin >> pp->sex;
			if (pp->sex ==1  ||  pp->sex == 2) {
				break;
			}
			else {
				cout << "�Ա�����Ĳ���ȷŶ,����������: (1 ->  ��,  2 -> Ů)" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin.clear();
			}
		}

		cout << "����Ҫ�޸ĵĵ绰:" << endl;
		cin >> pp->num;

		cout << "������Ҫ�޸ĵĵ�ַ: " << endl;
		cin >> pp->addr;
	}
	else {
		cout << "�����޴���." << endl;
	}

	clsScreen();
}

void delete_person(PersonNote *note) {
	if (note->m_Size <= 0) {
		cout << "�绰��Ϊ��..." << endl;
		return;
	}
	string name;
	cout << "������Ҫɾ�����û�������: " << endl;
	cin >> name;
	int ret = if_exists(note, name);
	if (ret >= 0) {
		int i;
		for (i = ret; i < note->m_Size; i++) {
			note->persons[i] = note->persons[i + 1];
		}
		note->m_Size--;
		cout << "ɾ���ɹ�." << endl;
	}
	else {
		cout << "���˲�����." << endl;
	}
	clsScreen();
}

void clear_note(PersonNote *note) {
	note->m_Size = 0;
	cout << "�����." << endl;

	clsScreen();
}