#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 안에서 "2번째 요소" 꺼내고 싶습니다.
	// => 직접 꺼내는 방법은 없습니다.

	// args 에 있는 모든 요소를 꺼내고 싶다면
	// 1. pack expansion - C++11
	// 2. fold expression - C++17 
	
	// 방법 1. 모든 요소의 타입이 동일하면 - 배열에 담아서 사용해도 됩니다.
	int x[] = { args... };

	// 방법 2. 요소의 타입이 다르면.. std::tuple 에 담아서 사용해도 됩니다.
	std::tuple<Types...> t(args...);

	std::cout << std::get<0>(t) << std::endl; // 튜플에서 0번째 꺼내기.
}


int main()
{
	foo(1, 2, 3);
}

