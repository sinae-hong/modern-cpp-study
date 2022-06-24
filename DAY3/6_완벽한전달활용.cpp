// 8_�Ϻ�������Ȱ�� - 122page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector�� ��� �ֱ�. 
	// 1. ��ü�� �������Ŀ� �ֱ�
	
//	Point pt(1, 2);
//	v.push_back(pt);

	// 2. �ӽð�ü ���·� ���� ����
//	v.push_back(Point(1, 2));

	// 3. ��ü�� ���� ������ ����..
	//    ��ü�� ����� ���� "���������ڰ�"�� ��������.
	//   ��ü ��ü�� vector�� ���������� ����� ����.

	v.emplace_back(1, 2);  
			// => emplace_back �Լ� �ȿ���
			// => new Point(1,2) �� ��ü ����


	std::cout << "-----" << std::endl;
}

// 1. vector<int> v ���� primitive Ÿ���� �����ϸ� �׳� push_back �ϼ���
//   => v.push_back(10);
//   => v.emplace_back(10) �ص� ���� ��������ϴ�.


// 2. ����� ���� Ÿ���� �����͸� �����ϸ� �׳� push_back �ϼ���
//   vector<Point*> v;
//   v.push_back( new Point(1,2))

// 3. ����� ���� Ÿ���� ������ �����ϸ�  push_xxx ���� ����, emplace_xxx �ϼ���
//  push_back  => emplace_back
//  push_front => emplace_front
//  insert     => emplace










