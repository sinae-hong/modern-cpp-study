// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� �Լ� ���� - 81 page
void goo(int n) {}

//void foo(Point& pt) {}  // temporary �� ������ �����ϴ�.
						// �̷��� ����� ������ "������ ����" �ϰڴٴ� �ǵ�
						// �̸� ���� ��ü�� �����Ѵٴ°��� �������� ��������
						// �׷��� "Point& pt = �ӽð�ü" �� ����

void foo(const Point& pt) {}// ������ �������� �ʰ� �б⸸ �ϰڴٴ°�
							// �ӽð�ü�� �޾Ƽ� �б⸸ �ϴ� ���� 
							// �������� Ʋ���� �ʴ�.
							// "const Point& pt = �ӽð�ü" �� ����

int main()
{
	int a = 10;
	goo(a); // �̸��ִ� ������ ���� ��Ƽ� ����
	goo(10); // ���� ��������, ������ ������ ���� "���ͷ�10"�� �ٷ� ������ �ȴ�.

//	Point pt(1, 2);
//	foo(pt);

	// �Լ� ���ڷθ� ����� ��ü�� �ʿ� �ϸ� "�ӽð�ü"���·� �����ϴ� ����
	// ȿ�����Դϴ�.
	foo( Point(1, 2) ); // �ӽð�ü�� "user type �� literal" �̶�� �θ��⵵ �մϴ�.


	std::cout << "-----" << std::endl;
}





