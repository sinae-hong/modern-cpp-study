// 3_레퍼런스1.cpp - 89 page - 아주 중요!

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(1, 2);

	// 규칙 1. non-const lvalue reference 는 lvalue 만 가리킬수 있다
	Point& r1 = pt;			 // ok
	Point& r2 = Point(1, 2); // error

	// 규칙 2. const lvalue reference 는 lvalue 와 rvalue 모두 가리킬수 있다
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(1, 2);	// ok

	// 규칙 3. C++11의 rvalue reference 는 rvalue 만 가리킬수 있다.
	Point&& r3 = pt;		  // error
	Point&& r4 = Point(1, 2); // ok

	// 참고 : const rvalue reference 는 rvalue 만
	//		=>그런데, 사용할 일이 없습니다. - 자세한것은 move 배울때
}




