class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// 복사 생성자를 사용자가 만들지 않으면
	// 컴파일러가 제공해 줍니다.
	// 컴파일러에게 복사 생성자를 만들지 못하게 하려면 삭제 하면 됩니다
	Point(const Point&) = delete; 
	
	Point operator=(const Point&) = delete; // 대입연산자도 만들지말라
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); // 이 코드가 왜 에러가 없나요 ?
				  // 컴파일러가 만들어주는 복사생성자사용
}

