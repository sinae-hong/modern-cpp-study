// 1_�ʱ�ȭ9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}		// 1
	Point(int, int) { std::cout << "int, int" << std::endl; }	// 2
	
	Point(std::initializer_list<int> e)							// 3
	{ std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);	// 1�� ������ ȣ��
//	Point p2{ 1 };	// 3��..������ 1�� ȣ��

	Point p3(1, 2);	// 2�� ������ ȣ��
	
	Point p4( { 1,2 } ); // 3�� ������ ȣ��
		
	Point p5{ 1,2 };	// 3�� ������ ȣ��, ������ 2�� ȣ��

//	Point p6(1, 2, 3); // error.  int �� 3���� ������ ����.

	Point p7{ 1, 2, 3 }; // ok. 3�� ������..
						// std::initializer_list �� ��� ������ �ִ�.
	
	Point p8 = { 1,2,3 };	// ok..

	Point p9 = { 1,2,3,4,5,6,7 };


	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; // ���� ���� �Ǽ��� ???
}


