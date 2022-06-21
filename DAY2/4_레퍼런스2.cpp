#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3

int main()
{
	int n = 10;
	foo(n);		// 1번 호출, 없으면 2번 호출
	foo(10);	// 3번 호출, 없으면 2번 호출

	// lvalue, rvalue 를 동일하게 처리하고 싶다.
	// => "const lvalue reference" 를 인자로 만드세요

	// lvalue, rvalue 를 다르게 처리하고 싶다.
	// => "lvalue reference", "rvalue reference" 함수를 따로 만드세요
}







