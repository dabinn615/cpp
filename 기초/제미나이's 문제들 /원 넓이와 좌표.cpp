#include <iostream>
#include <string>
using namespace std;
 
class Point{
private:
	double x; double y;

public:
	Point(double xx, double yy):x(xx),y(yy) {

	}

	double getX() {
		return x; //입력받은 x좌표 반환
	}

	double getY() {
		return y; //입력받은 y좌표 반환
	}
};

class Circle {
public:
	Point* center;
	double radius;

	Circle(Point* c, double r) : center(c), radius(r) {

	}

	double getArea() {
		return 3.14 * radius * radius;
	}

	bool isInside(Point* p) {
		double disx = p->getX() - this->center->getX(); 
		//매개변수 p의 주소에서 x좌표 가져오고, 지금 나의 중심점 주소로 가서 그 점의 x좌표 가져와서 빼기
		double disy = p->getY() - this->center->getY(); 
		//매개변수 p의 주소에서 y좌표 가져오고, 지금 나의 중심점 주소로 가서 그 점의 y좌표 가져와서 빼기

		double distance = ((disx) * (disx) + (disy) * (disy)) * 0.5;

		if (distance <= radius) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	double x, y, r;
	Point* c;
	cout << "원의 중심(x,y)과 반지름을 입력하세요: ";
	cin >> x >> y >> r;

	Point centerP(x, y); //중심점 객체 생성 
	Circle cc(&centerP, r); //중심좌표가 (x,y)인 원 생성 

	cout << "원의 면적: " << cc.getArea() << endl; 

	double px, py; //판별할 새로운 점 좌표
	cout << "원 안에 있는지 판별할 점의 좌표(x,y)를 입력하세요: ";
	cin >> px >> py;

	Point p(px, py); //판별할 점 객체 생성

	if (cc.isInside(&p)) {
		cout << "점(" << px << "," << py << ")는 원 안에 있습니다." << endl;
	}
	else {
		cout << "점(" << px << "," << py << ")는 원 밖에 있습니다." << endl;
	}

	return 0;
}
