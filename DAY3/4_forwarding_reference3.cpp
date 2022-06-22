#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	std::cout << __FUNCSIG__ << std::endl;  // vc
//	std::cout << __PRETTY_FUNCTION__ << std::endl;  // g++

	// 또는 godbolt.org
}

int main()
{
	int n = 10;

	foo(n);  // T=int&    T&&=int& &&   => int&
	foo(10); // T=int     T&&=int&&
}




