#include <iostream>
#include <type_traits> 

// C++20 에서는
// "enable_if + SFINAE" 의 개념을 문법으로 발전 시켰습니다.

// C++20 의 "concept" 이라는 문법입니다. 아래 처럼 코딩하게 됩니다.

template<typename T> requires std::is_pointer_v<T>
void printv(const T& v)
{
	// 포인터 일때
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> requires (!std::is_pointer_v<T>)
void printv(const T& v)
{
	// 포인터가 아닐때
	std::cout << v << std::endl
}





int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

