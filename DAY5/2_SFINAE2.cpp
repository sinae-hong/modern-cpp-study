#include <iostream>

// Substituion Failure Is Not An Error  => "SFINAE"

// �Լ� ���ø��� ����ϱ�� ������ �Ǿ��µ�, 
// T�� Ÿ���� �����ǰ�, ���� �Լ��� �����Ҷ�, ���и� �ߴ�(int::type ó��)

// => �� ��� ������ �ƴ϶�. ȣ�Ⱑ���� �ĺ������� ���� �ȴ�.
// => ������ �̸��� �ٸ� �Լ��� �ִٸ� ���ȴ�.!!


template<typename T>
//int foo(T a)  { std::cout << "T" << std::endl; return 0; }
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
// int::type foo(int a) { ....} �� �����Ϸ��� �����Ϸ��� �Ҷ�...


int foo(...) { std::cout << "..." << std::endl; return 0; }


int main()
{
	foo(3);		// ... ���� "T" ������ �켱������ ����.
}