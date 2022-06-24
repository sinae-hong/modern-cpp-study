#include <iostream>

// Substituion Failure Is Not An Error  => "SFINAE"

// 함수 템플릿을 사용하기로 결정이 되었는데, 
// T의 타입이 결정되고, 실제 함수를 생성할때, 실패를 했다(int::type 처럼)

// => 이 경우 에러가 아니라. 호출가능한 후보군에서 제외 된다.
// => 동일한 이름의 다른 함수가 있다면 사용된다.!!


template<typename T>
//int foo(T a)  { std::cout << "T" << std::endl; return 0; }
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
// int::type foo(int a) { ....} 로 컴파일러가 생성하려고 할때...


int foo(...) { std::cout << "..." << std::endl; return 0; }


int main()
{
	foo(3);		// ... 보다 "T" 버전이 우선순위가 높다.
}