// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void goo(int n) {}

//void foo(Point& pt) {}  // temporary 를 받을수 없습니다.
						// 이렇게 만드는 이유는 "원본을 수정" 하겠다는 의도
						// 이름 없는 객체를 수정한다는것은 논리적으로 맞지않음
						// 그래서 "Point& pt = 임시객체" 는 에러

void foo(const Point& pt) {}// 원본을 수정하지 않고 읽기만 하겠다는것
							// 임시객체를 받아서 읽기만 하는 것은 
							// 논리적으로 틀리지 않다.
							// "const Point& pt = 임시객체" 는 가능

int main()
{
	int a = 10;
	goo(a); // 이름있는 변수에 값을 담아서 전달
	goo(10); // 값만 보내려면, 변수를 만들지 말고 "리터럴10"을 바로 보내도 된다.

//	Point pt(1, 2);
//	foo(pt);

	// 함수 인자로만 사용할 객체가 필요 하면 "임시객체"형태로 전달하는 것이
	// 효율적입니다.
	foo( Point(1, 2) ); // 임시객체를 "user type 의 literal" 이라고 부르기도 합니다.


	std::cout << "-----" << std::endl;
}





