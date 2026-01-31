#include <iostream>
#include <string>
using namespace std;

class Coffee {
public:
	string name;

	Coffee(string n) :name(n) {

	}
	virtual void taste() { //함수가 void 타입이면 아무것도 반환하지 않음
		cout << name << "는 씁쓸한 커피 맛입니다." << endl;
	}

};

class Latte :public Coffee {
public:
	Latte(string n) : Coffee(n) {

	}

	void taste() override {
		cout << name << "는 우유가 들어가 부드러운 맛입니다." << endl;
	}
};

int main() {
	Coffee coffee1("아메리카노");
	coffee1.taste(); // Coffee 클래스의 taste() 함수 호출 (이미 함수에 출력코드가 있으므로 호출만 함!!)
	Latte latte1("카페라떼");
	latte1.taste(); // Latte 클래스의 taste() 함수 호출 (이미 함수에 출력코드가 있으므로 호출만 함!!)

	Coffee* mydrink1 = new Latte("카페모카"); //Coffee* mydrink1은 mydrink1에 Coffee나 그 자식 객체의 주소를 저장할 수 있음 (컵 개념)
	mydrink1->taste(); // Latte 클래스의 taste() 함수 호출 (이미 함수에 출력코드가 있으므로 호출만 함!!) (만약 new Coffee 였다면 Coffee의 taste()함수가 호출됨)
	delete mydrink1; //동적할당한 메모리 해제

	Coffee* cafe[3]; // 커피 컵 3개를 준비!
	cafe[0] = new Coffee("아메리카노");
	cafe[1] = new Latte("바닐라라떼");
	cafe[2] = new Latte("초코라떼");

	for (int i = 0; i < 3; i++) {
		cafe[i]->taste(); // 종류가 달라도 한 번에 맛을 볼 수 있음!
		delete cafe[i]; //동적할당한 메모리 해제
	}
	
	return 0;
}
