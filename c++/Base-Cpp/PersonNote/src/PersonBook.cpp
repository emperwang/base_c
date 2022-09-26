#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define MAX 100
/*
一个简单的通讯录的实现
*/

struct Person {
	string m_Name;
	int age;
	string num;
	int sex;
	string addr;
};

struct PersonNote {
	// 存储具体的信息
	struct Person persons[MAX];
	// 记录人数
	int m_Size;
};

void clsScreen() {
	system("pause");
	system("cls");
}

void printItems() {
	cout << "\t*********电话簿操作***********" << endl;
	cout << "\t***-- 1.添加用户 *************" << endl;
	cout << "\t***-- 2.打印用户 *************" << endl;
	cout << "\t***-- 3.查找用户 *************" << endl;
	cout << "\t***-- 4.修改用户 *************" << endl;
	cout << "\t***-- 5.删除用户 *************" << endl;
	cout << "\t***-- 6.清空电话簿************" << endl;
	cout << "\t***-- 7.退出     *************" << endl;
	cout << "\t******************************" << endl;
	cout << endl;

	cout << "请输入您的选择: " << endl;
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
	// 定义电话簿
	PersonNote note;
	note.m_Size = 0;	// 初始人数为0

	while (true)
	{
		begin:
		printItems();
		// 每次读取之前清空读取缓冲区中的内容
		// 这样每次读取时,上次输入的值就不会有影响
		//cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		//cin.clear();
		//cin.getline(select,sizeof(select));
		cin.get(select, sizeof(select));
		//cout << "input val: " << select<<" ,int val: "<< ((int)select[0]) << endl;
		if ( ((int)select[0]) < 49 || ((int)select[0]) > 55) {
			cout << "输入有误，请重新输入(1-7)."<<endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
			goto begin;
		}
		switch ((int)select[0]) {
		case 49:		//1.添加用户
			insert_person(&note);
			break;
		case 50:		//2.打印用户
			print_note(&note);
			break;
		case 51:		// 3.查找用户
			find_person(&note);
			break;
		case 52:		// 4.修改用户
			update_person(&note);
			break;
		case 53:		// 5.删除用户
			delete_person(&note);
			break;
		case 54:		// 6.清空电话簿
			clear_note(&note);
			break;
		case 55:		// 7. 退出
			cout << "谢谢使用,期待您的下次光临." << endl;
			clsScreen();
			return 0;
		default:
			cout << "switch输入有误，请重新输入." << endl;
			clsScreen();
			break;
		}
	}

	clsScreen();
}

void insert_person(PersonNote *note) {
	struct Person p;
	cout << "请输入姓名: " << endl;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cin >> p.m_Name;

	cout << "请输入年龄: " << endl;
	while (true){
		cin >> p.age;
		if (p.age>0 && p.age < 200){
			break;
		}
		else {
			cout << "年龄输入不太对哦，请重新输入(1-200)" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
		}
	}

	cout << "请输入性别:  1 -> 男    2->女" << endl;
	
	while (true){
		cin >> p.sex;
		if (p.sex == 1 || p.sex == 2) {
			break;
		}
		else {
			cout << "性别输入不太对哦，请重新输入.1 -> 男    2->女" << endl;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
		}
	}

	cout << "请输入电话: " << endl;
	cin >> p.num;

	cout << "请输入地址: " << endl;
	cin >> p.addr;

	note->persons[note->m_Size] = p;

	note->m_Size++;

	clsScreen();
}
void print_note(PersonNote *note) {
	if (note->m_Size <= 0) {
		cout << "电话簿为空..." << endl;
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
	cout << "姓名: " << p.m_Name << "\t";
	cout << "年龄: " << p.age << "\t";
	cout << "性别: " << (p.sex == 1 ? "男" : "女") << "\t";
	cout << "手机: " << p.num << "\t";
	cout << "地址: " << p.addr << endl;
}

int if_exists(PersonNote *note, string name) {
	if (note->m_Size <= 0) {
		cout << "通讯录为空." << endl;
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
		cout << "电话簿为空..." << endl;
		return;
	}
	string name;
	cout << "请输入要查询的用户的姓名: " << endl;
	cin >> name;
	int ret = if_exists(note, name);
	if (ret >= 0) {
		print_person(note->persons[ret]);
	}
	else {
		cout << "查找无此人." << endl;
	}
	clsScreen();
}

void update_person(PersonNote *note) {
	if (note->m_Size <= 0) {
		cout << "电话簿为空..." << endl;
		return;
	}
	string name;
	cout << "请输入要更新的用户的姓名: " << endl;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cin >> name;
	int ret = if_exists(note, name);
	if (ret >= 0) {
		Person* pp = &note->persons[ret];
		cout << "请输入要修改的姓名: " << endl;
		cin >> pp->m_Name;
		
		cout << "请输入要修改的年龄: " << endl;
		while (true) {
			cin >> pp->age;
			if (pp->age > 0 && pp->age < 200) {
				break;
			}
			else {
				cout << "年龄输入的不正确哦,请重新输入: (0-200)" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin.clear();
			}
		}

		cout << "请输入要修改的性别: 1 ->  男,  2 -> 女 " << endl;
		while (true) {
			cin >> pp->sex;
			if (pp->sex ==1  ||  pp->sex == 2) {
				break;
			}
			else {
				cout << "性别输入的不正确哦,请重新输入: (1 ->  男,  2 -> 女)" << endl;
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cin.clear();
			}
		}

		cout << "请入要修改的电话:" << endl;
		cin >> pp->num;

		cout << "请输入要修改的地址: " << endl;
		cin >> pp->addr;
	}
	else {
		cout << "查找无此人." << endl;
	}

	clsScreen();
}

void delete_person(PersonNote *note) {
	if (note->m_Size <= 0) {
		cout << "电话簿为空..." << endl;
		return;
	}
	string name;
	cout << "请输入要删除的用户的姓名: " << endl;
	cin >> name;
	int ret = if_exists(note, name);
	if (ret >= 0) {
		int i;
		for (i = ret; i < note->m_Size; i++) {
			note->persons[i] = note->persons[i + 1];
		}
		note->m_Size--;
		cout << "删除成功." << endl;
	}
	else {
		cout << "此人不存在." << endl;
	}
	clsScreen();
}

void clear_note(PersonNote *note) {
	note->m_Size = 0;
	cout << "已清空." << endl;

	clsScreen();
}