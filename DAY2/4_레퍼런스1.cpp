// 3_���۷���1.cpp - 89 page - ���� �߿�!

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(1, 2);

	// ��Ģ 1. non-const lvalue reference �� lvalue �� ����ų�� �ִ�
	Point& r1 = pt;			 // ok
	Point& r2 = Point(1, 2); // error

	// ��Ģ 2. const lvalue reference �� lvalue �� rvalue ��� ����ų�� �ִ�
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(1, 2);	// ok

	// ��Ģ 3. C++11�� rvalue reference �� rvalue �� ����ų�� �ִ�.
	Point&& r3 = pt;		  // error
	Point&& r4 = Point(1, 2); // ok

	// ���� : const rvalue reference �� rvalue ��
	//		=>�׷���, ����� ���� �����ϴ�. - �ڼ��Ѱ��� move ��ﶧ
}




