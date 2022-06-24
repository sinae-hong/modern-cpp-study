#include <iostream>

// 233 page 입니다.

// 재귀와 유사한 기술 사용하기
// 핵심 : 모든 인자를 가변으로 하지말고, 한개는 독립된 타입으로 하세요


void foo() {} // 재귀의 종료를 위해

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int cnt = 0;
	++cnt;

	std::cout << cnt << ", " << value << std::endl;

//	foo(args...);  // foo(3.4, 'A')
				   // foo('A')
				   // foo()

	// C++17 부터는 아래 코드가 좀더 편리합니다. - "인자가 없는 foo()" 필요 없습니다.
	// => if constexpr 때문에 C++17 부터.
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A'); // value : 1,   args : 3.4, 'A'
}







