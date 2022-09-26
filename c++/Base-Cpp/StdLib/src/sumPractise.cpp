#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;
// 5个选手，10个评委个选手打分，去掉一个最低分，去掉一个最高分，求平均分


// 首先定义选手
class singer {
public:
	string m_name;
	int score;

	void showInfo() const{
		cout << "姓名: " << this->m_name
			<< ", 得分 :" << this->score << endl;
	}

	singer(string name, int score) {
		this->m_name = name;
		this->score = score;
	}
};

void createSinger(vector<singer> &v) {
	string s = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string ss = "选手";
		ss += s[i];
		singer sg(ss, 0);
		v.push_back(sg);
	}
}


void printScores(deque<int> &sc) {
	for (deque<int>::iterator it = sc.begin(); it != sc.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int getAvg(deque<int> &sc) {
	int sum = 0;
	for (deque<int>::iterator it = sc.begin(); it != sc.end(); it++) {
		sum += *it;
	}
	int avg = sum / sc.size();
	cout << "sum = " << sum<< endl;
	cout << "avg = " << avg << endl;

	return avg;
}

// 打分
void setSocre(vector<singer>  &v) {
	for (vector<singer>::iterator it = v.begin(); it != v.end(); it++) {

		deque<int> scores;
		for (int i = 0; i < 10; i++) {
			int tmp = rand() % 41 + 60;  // 产生 60~100的随机数
			scores.push_back(tmp);
		}
		//printScores(scores);
		sort(scores.begin(), scores.end());
		//printScores(scores);

		scores.pop_back();
		scores.pop_front();
		printScores(scores);
		it->score = getAvg(scores);
	}
}


void printSigner(const vector<singer> &s) {
	for (vector<singer>::const_iterator it = s.begin(); it != s.end(); it++) {
		it->showInfo();
	}
}

//int main() {
//
//	vector<singer> vs;
//	
//	//1. 创建选手
//	createSinger(vs);
//	printSigner(vs);
//
//	//2. 设置分数
//	setSocre(vs);
//
//	//3. 打印分数
//	printSigner(vs);
//
//	system("pause");
//	return 0;
//}