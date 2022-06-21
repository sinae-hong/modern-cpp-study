// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }

	Point(const Point& p) { std::cout << "Point(const Point&)" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// �ӽð�ü�� �Լ� ��ȯ�� -  82 page

void f1(Point  pt) {} // call by value : ���纻 ��ü ����
void f2(Point& pt) {} // call by reference :  ���纻 ��ü ���� �ȵ�

/*
int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/





Point pt(1, 2);

Point foo() // return by value : ���Ͽ� �ӽð�ü ����
{
	return pt; 
}
Point& goo() // return by reference 
{
	return pt;
}

int main()
{
//	foo().x = 10; // error. �ӽð�ü.x = 10
//	goo().x = 10; // ok..  pt.x = 10 

	std::cout << "---------" << std::endl;
	//foo();
	goo();
	std::cout << "---------" << std::endl;
}



// return by value : �޸𸮰� �ƴ� "��"�� ��ȯ
//int x = 10;
//int   f3() { return x; } // x�� �� "10" ��ȯ
//Point f4() { return pt; }// pt�� �� "1,2" ��ȯ
						 // "Point(1,2)"  => ����� ���� Ÿ���� ���ͷ�

// ���� ���� : ���������� ���� ���� ��ȯ�ϸ� �ȵ˴ϴ�

Point& hoo()
{
	Point pt(1,2);
	return pt; // pt�� �Լ� ����� �ٷ� �ı� �˴ϴ�.
				// ���� ���� ��ȯ �ϸ� �ȵ˴ϴ�.
				// �ݵ�� "��" ��ȯ�����ؾ� �մϴ�.
}



