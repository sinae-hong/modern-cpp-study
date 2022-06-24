#include <iostream>

// fold expression - C++17
// => 파라미터 팩의 모든 요소에 대해 이항연산을 수행하는 것

template<typename ... Types>
auto sum(Types ... args)
{
	// ( pack_name  이항연산 ... )  <= 주의 () 반드시 필요
//	int n = (args + ...); // (1+(2+(3+(4+(5+(6+(7+(8+(9+10))))))))
//	int n = (... + args); // (((((1+2)+3)+4) ....)

	// 0 을 초기값(init) 이라고 합니다
//	int n = (args + ... + 0); // (1+(2+(3+(4+(5+(6+(7+(8+(9+(10+ 0))))))))
	
	int n = (0 + ... + args); // (((((0+1)+2)+3)+4) ....)
	return n;
}

int main()
{
//	int n = sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int n = sum();
	std::cout << n << std::endl;
}