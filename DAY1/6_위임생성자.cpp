#include <iostream>
// 6_위임생성자 - 24page

class Base {};

class Point : public Base
{
public:
	int x, y;
public:
	// C++98 : 하나의 생성자에서 다른 생성자를 호출할수 없다.
	// C++11 : 하나의 생성자에서 다른 생성자를 호출할수 있다.( 위임 생성자라는 문법)

	// 사용자 코드		// 컴파일러가 변경한 코드
//	Point()				// Point() : Base()
	Point() : Point(0,0)// 위임 생성자 라는 문법 - 이 경우. 여기에는 
	{								// 기반 클래스 생성자 호출하는 코드 추가되지 않음

	//	Point(0, 0); // 생성자에서 다른 생성자 호출 <= 아닙니다
					 // 이 표기법은 내일 배우는 "임시객체" 를 만드는 표기법입니다.
					 // 즉, 객체의 생성입니다.
		
	}
	Point(int a, int b) : x(a), y(b)  // Point(int a, int b) : Base(), x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
	
	void init()
	{
	}
};

int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

