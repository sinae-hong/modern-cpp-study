#include <iostream>


template<typename ... Types> void foo(Types ... args)
{
	// main ���� foo(1, 3.4, 'A') �� ��������Ƿ�

	// �ٽ� 1. "parameter pack" �̶�� ���!
	// Types : int, double, char  => "template parameter pack"
	// args  : 1,   3.4,    'A'   => "function parameter pack"

	// �ٽ� 2. sizeof...

	std::cout << sizeof...(Types) << std::endl;
	std::cout << sizeof...(args)  << std::endl;
}

int main()
{
	foo(1, 3.4, 'A');
}