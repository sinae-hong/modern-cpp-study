// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			// ok
	Point(1, 2).x = 10;	// error. 임시객체는 등호의 왼쪽에 올수 없다
						//		  "lvalue 가 될수 없다" 라고 표현

	// 주의.. 임시객체가 상수인것은 아닙니다.
//	Point(1, 2).set(10, 20); // 이렇게 함수 호출로 변경가능합니다
						

	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error. 임시객체는 주소연산자로 주소를
								// 구할수 없습니다
								// 하지만, 생성자에서 this를 사용할수는 있습니다.

	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error. 

	// 중요!. 임시객체를 상수 참조로는 가리킬수 있습니다 - C++98
	const Point& r3 = Point(1, 2); // ok. 
				// 이 경우 임시객체의 수명은 r3로 연장됩니다.
				// 왜, 이런 문법을 만들었습니까 ? => 다음 예제에서.. 
	// 특징. 상수성이 추가되어서 값을 변경할수 없습니다
//	r3.x = 10;// error

	// C++11 만들때 "상수성 없이 임시객체를 가리키고 싶었습니다."
	// => "Move" 와 "완벽한 전달" 문법을 만들기 위해
	// 그래서 "rvalue reference" 라는 문법이 도입되었습니다
	Point&& r5 = Point(1, 2); //ok
	Point&& r6 = pt; // error
}





