// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� Ư¡ - 79 page
int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			// ok
	Point(1, 2).x = 10;	// error. �ӽð�ü�� ��ȣ�� ���ʿ� �ü� ����
						//		  "lvalue �� �ɼ� ����" ��� ǥ��

	// ����.. �ӽð�ü�� ����ΰ��� �ƴմϴ�.
//	Point(1, 2).set(10, 20); // �̷��� �Լ� ȣ��� ���氡���մϴ�
						

	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error. �ӽð�ü�� �ּҿ����ڷ� �ּҸ�
								// ���Ҽ� �����ϴ�
								// ������, �����ڿ��� this�� ����Ҽ��� �ֽ��ϴ�.

	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error. 

	// �߿�!. �ӽð�ü�� ��� �����δ� ����ų�� �ֽ��ϴ� - C++98
	const Point& r3 = Point(1, 2); // ok. 
				// �� ��� �ӽð�ü�� ������ r3�� ����˴ϴ�.
				// ��, �̷� ������ ��������ϱ� ? => ���� ��������.. 
	// Ư¡. ������� �߰��Ǿ ���� �����Ҽ� �����ϴ�
//	r3.x = 10;// error

	// C++11 ���鶧 "����� ���� �ӽð�ü�� ����Ű�� �;����ϴ�."
	// => "Move" �� "�Ϻ��� ����" ������ ����� ����
	// �׷��� "rvalue reference" ��� ������ ���ԵǾ����ϴ�
	Point&& r5 = Point(1, 2); //ok
	Point&& r6 = pt; // error
}





