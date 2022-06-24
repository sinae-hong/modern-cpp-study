// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n1{ 0 };	// direct initialization
	int n2 = { 0 };	// copy initialization
	int n3;			// default initialization
	int n4{};		// value initialization. 
					// 0으로 초기화!

	std::cout << n4 << std::endl; // 0

	Point pt{}; // 모든 멤버를 모두 0으로 초기화
				// 단, 사용자가 제공한 생성자가 없을때만..

	std::cout << pt.x << std::endl;
}


