// 1_초기화11 - 65 page..
// aggregate initialization
// aggregate 타입 : 모든 요소를 {} 로 초기화 할수 있는타입
//				C 구조체, 배열 등
struct Point
{
	int x, y = 0; // 이렇게 초기값이 있으면 "trivial"은 아닌데.
					// aggregate 타입은 됩니다.

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

	void foo() {}	// 멤버 함수 있어도 aggregate 타입입니다.

//	virtual void goo() {}	//가상함수가 있으면 aggregate 아님.

//	Point() {}		// 이 생성자 있으면 aggregate 아님.

	Point() = default;
};


int main()
{
	Point p1;	
	Point p2 = { 1,2 };

//	Point p2(1, 2);
}