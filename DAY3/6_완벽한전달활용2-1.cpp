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
	std::cout << "new ��� : " << sz << " bytes" << std::endl;

	return malloc(sz);
}
int main()
{
	// �Ʒ� ������ �ڵ�� new �� ����ұ�� ? 2��
	// 1. ����ڰ� ���� "new Point(1,2)" 
	// 2. shared_ptr �����ڿ��� "������ü" ���鶧..
//	std::shared_ptr<Point> sp1( new Point(1,2) );

//	std::cout << sizeof(sp1) << std::endl;

	// �Ʒ� �ڵ�� ��ü ������ ����Ʈ ������ ������ �ѹ��� �˴ϴ�.
	// �׷���, sizeof(Point) + sizeof(������ü) �� �޸𸮸� �ѹ��� �Ҵ��մϴ�.
	// �޸� ����ȭ ������ �پ� ��ϴ�.
	// ���, "make_shared" �� �׻� �����ϴ�.
	// => make_shared �� �ᱹ �Ϻ��� ���޷� ������ ��� �Դϴ�.
	std::shared_ptr<Point> sp3 = std::make_shared<Point>(1, 2);
		
}
// 3:45�� ~











