// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }

	Point(const Point& p) { std::cout << "Point(const Point&)" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page

void f1(Point  pt) {} // call by value : 복사본 객체 생성
void f2(Point& pt) {} // call by reference :  복사본 객체 생성 안됨

/*
int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/





Point pt(1, 2);

Point foo() // return by value : 리턴용 임시객체 생성
{
	return pt; 
}
Point& goo() // return by reference 
{
	return pt;
}

int main()
{
//	foo().x = 10; // error. 임시객체.x = 10
//	goo().x = 10; // ok..  pt.x = 10 

	std::cout << "---------" << std::endl;
	//foo();
	goo();
	std::cout << "---------" << std::endl;
}



// return by value : 메모리가 아닌 "값"을 반환
//int x = 10;
//int   f3() { return x; } // x의 값 "10" 반환
//Point f4() { return pt; }// pt의 값 "1,2" 반환
						 // "Point(1,2)"  => 사용자 정의 타입의 리터럴





