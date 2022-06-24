// 1_초기화9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}		// 1
	Point(int, int) { std::cout << "int, int" << std::endl; }	// 2
	
	Point(std::initializer_list<int> e)							// 3
	{ std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);	// 1번 생성자 호출
//	Point p2{ 1 };	// 3번..없으면 1번 호출

	Point p3(1, 2);	// 2번 생성자 호출
	
	Point p4( { 1,2 } ); // 3번 생성자 호출
		
	Point p5{ 1,2 };	// 3번 생성자 호출, 없으면 2번 호출

//	Point p6(1, 2, 3); // error.  int 가 3개인 생성자 없다.

	Point p7{ 1, 2, 3 }; // ok. 3번 생성자..
						// std::initializer_list 는 몇개라도 받을수 있다.
	
	Point p8 = { 1,2,3 };	// ok..

	Point p9 = { 1,2,3,4,5,6,7 };


	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; // 원리 이해 되세요 ???
}


