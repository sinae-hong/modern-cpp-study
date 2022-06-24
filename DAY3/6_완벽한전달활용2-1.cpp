#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

void* operator new(std::size_t sz)
{
	std::cout << "new 사용 : " << sz << " bytes" << std::endl;

	return malloc(sz);
}
int main()
{
	// 아래 한줄의 코드는 new 를 몇번할까요 ? 2번
	// 1. 사용자가 만든 "new Point(1,2)" 
	// 2. shared_ptr 생성자에서 "관리객체" 만들때..
//	std::shared_ptr<Point> sp1( new Point(1,2) );

//	std::cout << sizeof(sp1) << std::endl;

	// 아래 코드는 객체 생성과 스마트 포인터 생성이 한번에 됩니다.
	// 그래서, sizeof(Point) + sizeof(관리객체) 의 메모리를 한번에 할당합니다.
	// 메모리 파편화 현상이 줄어 듭니다.
	// 결론, "make_shared" 가 항상 좋습니다.
	// => make_shared 는 결국 완벽한 전달로 구현된 기술 입니다.
	std::shared_ptr<Point> sp3 = std::make_shared<Point>(1, 2);
		
}
// 3:45분 ~











