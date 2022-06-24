// 8_완벽한전달활용 - 122page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 1. 객체를 생성한후에 넣기
	
//	Point pt(1, 2);
//	v.push_back(pt);

	// 2. 임시객체 형태로 만들어서 전달
//	v.push_back(Point(1, 2));

	// 3. 객체를 만들어서 보내지 말고..
	//    객체를 만들기 위한 "생성자인자값"만 전달하자.
	//   객체 자체는 vector가 내부적으로 만들게 하자.

	v.emplace_back(1, 2);  
			// => emplace_back 함수 안에서
			// => new Point(1,2) 로 객체 생성


	std::cout << "-----" << std::endl;
}

// 1. vector<int> v 같이 primitive 타입을 보관하면 그냥 push_back 하세요
//   => v.push_back(10);
//   => v.emplace_back(10) 해도 전혀 상관없습니다.


// 2. 사용자 정의 타입의 포인터를 보관하면 그냥 push_back 하세요
//   vector<Point*> v;
//   v.push_back( new Point(1,2))

// 3. 사용자 정의 타입을 값으로 보과하면  push_xxx 하지 말고, emplace_xxx 하세요
//  push_back  => emplace_back
//  push_front => emplace_front
//  insert     => emplace










