#include <iostream>
#include <type_traits>

// trivial 생성자 : 아무일도 하지 않는 생성자를 trivial 하다고 합니다.
//					사용자가 생성자 몸체를 제공하면 trivial 하지 않습니다.

struct Point
{
	int x, y = 0;

	Point() = default; // 이렇게 만들면 trivial
//	Point() {}			// 이렇게 만들면 trivial 하지 않음
};

int main()
{
	std::cout << std::is_trivially_default_constructible<Point>::value
		      << std::endl;

	Point pt{}; // 모든 멤버를 0으로 해달라는 것. - C++11에서 추가된 문법
				// "초기화" 배울때 자세히 설명
				// "단, 생성자가 trivial 할때만 0으로"

	std::cout << pt.x << std::endl;
}