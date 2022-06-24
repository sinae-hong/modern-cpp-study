// move 는 교재 99 page ~

// 복사 생성자 다시 보기
class Point
{
	int x, y;
public:
	Point() {  }				// 1번
	Point(int a, int b) {  }	// 2번

	// 복사 생성자 모양을 생각해 봅시다.
	// 1. call by value : 복사 생성자가 무한히 호출되는 모양
	//					  컴파일 에러 발생
//	Point(Point pt) {} // 인자를 받을때 "Point pt = p3;" => Point pt(p3)
						// 즉, 다시 복사 생성자 호출

	// 2. call by reference : 가능한 방법.. 컴파일 에러 아님.
	// 단점 : rvalue 를 받을수 없다.
	//       "값타입" 으로 반환하는 함수의 반환 값을 받을수 없다.
//	Point(Point& pt) {} // "Point& pt = p3"  

	// 3. 복사 생성자는 "rvalue", "lvalue" 를 모두 받아야 한다.
	//    const - lvalue reference 밖에 없다.
	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point pt(1, 2);
	return pt;
}
int main()
{
	Point p1;		// 1번 생성자 사용
//	Point p2(1);	// error. Point(int) 모양의 생성자가 없다.
	Point p3(1, 2);	// 2번 생성자 사용
	Point p4(p3);	// Point(Point) 모양의 생성자 필요
					//	=> 복사 생성자.
					//	=> 사용자가 만들지 않으면 컴파일러가 제공
	Point ret = foo();
}



