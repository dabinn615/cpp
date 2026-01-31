#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private: //외부에서 직접 수정X!!
	int balance;

public:

	BankAccount(int b) : balance(b) {
	
	}

	void deposit(int amount) {
		if (amount > 0) {
			balance += amount;
			cout << amount << "원 입금 완료. 잔액: " << balance << endl;
		}
	}

	bool withdraw(int amount) { //반환 타입이 true/false면 bool 사용!!
		if (amount <= balance) {
			balance -= amount;
			cout << amount << "원 출금 완료. 잔액: " << balance << endl;
			return true;
		}
		else {
			cout << "잔액 부족" << endl;
			cout << amount - balance << "원이 부족합니다. 출금 불가합니다." << endl;
			return false;
		}
	}
};

int main() {
	int jango;
	cout << "초기 잔고 입력: ";
	cin >> jango;
	BankAccount mymoney(jango);

	while (true) {
		string select;
		cout << "입금하시겠습니까? 아니면 출금하시겠습니까? : ";
		cin >> select;

		if (select == "입금") {
			cout << "얼마를 입금하시겠습니까? : ";
			int amount;
			cin >> amount;
			mymoney.deposit(amount);
		}

		else if (select == "출금") {
			cout << "얼마를 출금하시겠습니까? : ";
			int amount;
			cin >> amount;
			if (mymoney.withdraw(amount) == false) { //if (함수호출 == 값)이라고 쓰면 실제로 함수 실행 뒤 결과값 가져옴!
				break;
			}
			else {
				continue;
			}
		}
	}
	
	return 0;
}
