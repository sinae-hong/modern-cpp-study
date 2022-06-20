// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	// 아무일도 하지 않는 디폴트 생성자를 만드는 방법
//	Point() {}			// 1. 사용자가 직접 구현
	Point() = default;	// 2. 컴파일러에게 요청

	Point(int a, int b) {}
};

int main()
{
	Point p1;
	Point p2(1, 2); // ok
}




