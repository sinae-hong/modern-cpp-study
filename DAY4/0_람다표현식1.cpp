#include <iostream>

// 129 page
// �Լ� ��ü(function object)
// => () �����ڸ� �������ؼ� �Լ� ó�� ��밡���� ��ü
// => functor ��� �մϴ�.

// �Լ��� ����ϸ� �Ǵµ�,, �� �Լ� ��ü�� ����մϱ� ?
// => ������ ���� �����ϴ�.
struct plus
{
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

int main()
{
	plus p;	// p �� �Լ��� �ƴ� ��ü �Դϴ�.	

	int n1 = p(1, 2); // p �� �Լ� ó�� ���˴ϴ�.
	int n2 = p.operator()(1, 2); // �� ������ ������ �� �ڵ� �Դϴ�.

	// a + b => a.operator+(b)
}



