
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

/*
class Rect
{
	Point pt; // ?
public:
	// 사용자 코드	컴파일러가 변경한 코드
//	Rect()			// Rect() : pt()  //<= 컴파일러가 pt의 디폴트 생성자호출하는코드추가

	// C++98 시절 해결책
	// => 디폴트 생성자가 없는 타입의 멤버 데이타가 있다면 아래처럼 명시적으로 생성자호추
	Rect() : pt(0, 0)  
	{
	}
};
*/

class Rect
{
	// C++11 부터는 디폴트 생성자가 없는 타입의 경우
	// 아래 처럼 해도 됩니다.
	Point pt{ 0, 0 };
//	Point pt(0, 0); //error. 중괄호만 가능
public:
	Rect()
	{
	}
};

int main()
{
	Rect r1;
}

