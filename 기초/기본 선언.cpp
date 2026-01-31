#include <iostream> //cout을 인식하기 위함
#include <string> //string을 인식하기 위함
using namespace std; //std::cout를 std 없이 사용하기 위해 필요
int main() {
	int age;
	string name;
	cin >> age; //사용자로부터 값을 가져옴 (c언어의 scanf와 비슷)
	cin >> name; 
	cout << "Let's introduce myself." << endl; //화면에 값을 보여줌 (출력)
	cout << "My name is " << name << endl;
	cout << "I'm " << age << " years old" << endl;
	
	return 0;
}
