// 1_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // named object, �ڽ��� ������ ���� ����� �ı�
//	Point (1, 2);   // unnamed object, �ڽ��� ������ ������ ������ �ı�
					// �ӽð�ü(temporary) ��� �մϴ�.
					// C++98 �������� ���� �������� ����

	Point(1, 2), std::cout << "X" << std::endl;

	std::cout << "-------" << std::endl;
}





