// 1_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // named object, 자신을 선언한 블럭을 벗어날때 파괴
//	Point (1, 2);   // unnamed object, 자신을 선언한 문장의 끝에서 파괴
					// 임시객체(temporary) 라고도 합니다.
					// C++98 시절부터 사용된 전통적인 문법

	Point(1, 2), std::cout << "X" << std::endl;

	std::cout << "-------" << std::endl;
}





