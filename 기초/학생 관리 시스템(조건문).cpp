#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	string name;
	int score;

	Student(string n, int s) : name(n), score(s) {

		if (score < 0) {
			score = 0;
		}
		else if (score > 100) {
			score = 100;
		}
	}

	string isPass() {
		if (score >= 60) {
			return "합격";
		}
		else {
			return "불합격";
		}
	}

};

int main() {
	string n;
	int s;
	cin >> n >> s;
	Student student(n, s);
	cout << student.name << "은(는) " << student.score << "점 이므로 " << student.isPass() << "입니다." << endl;

	string name[3];
	int score[3];
	for (int i = 0;i < 3;i++) {
		cin >> name[i] >> score[i];
		Student student1(name[i], score[i]);
		cout << student1.name << "은(는) " << student1.score << "점 이므로 " << student1.isPass() << "입니다." << endl;
	}

	return 0;
}
