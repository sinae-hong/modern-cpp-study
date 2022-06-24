#include <iostream>


template<typename ... Types> void foo(Types ... args)
{
	// main 에서 foo(1, 3.4, 'A') 로 사용했으므로

	// 핵심 1. "parameter pack" 이라는 용어!
	// Types : int, double, char  => "template parameter pack"
	// args  : 1,   3.4,    'A'   => "function parameter pack"

	// 핵심 2. sizeof...

	std::cout << sizeof...(Types) << std::endl;
	std::cout << sizeof...(args)  << std::endl;
}

int main()
{
	foo(1, 3.4, 'A');
}