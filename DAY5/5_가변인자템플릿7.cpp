// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// 가변인자 템플릿은 아주 널리 사용되는 것은 아닙니다.
// 꼭 필요한 경우가 있습니다..
// 아래 같이...

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
//	return f( std::forward<Types>(args) ); // error. 함수에 pack 이름 전달 안됨
//	return f(std::forward<Types>(args...)); //  forward(1,2,n) 의 의미, 
											//그런데 forward는 인자가 한개
	return f(std::forward<Types>(args)... );
			// f( std::forward<int>(1),std::forward<int>(2), std::forward<int&>(n) )
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

