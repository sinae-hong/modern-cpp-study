#include <iostream>
// 1. 리턴 타입을 표기(후위반환문법으로) 하는 경우
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a* b)
{
	return a * b;
}

// 2. C++14 부터 리턴 타입 생략 가능합니다. return 문으로 타입 추론
// => return 문장이 여러개 이고, 각각 타입이 다르면 추론 안됨. 
// => 그 경우, 위처럼 표기해야 한다.
// => return 표현식이 결과가 참조(int&)라면 참조를 제거하고 타입 결정(int반환)
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b)
{
	return a * b;
}
// C++14 부터, 아래처럼도 가능
// => return 문의 결과가 참조 라면 리턴 타입도 참조로 해달라는 것
// => 이 표기법이 꽤 널리 사용됨.
template<typename T1, typename T2>
decltype(auto) Mul2(T1 a, T2 b)
{
	return a * b;
}


int main()
{
	std::cout << Mul(1, 2.2) << std::endl;
}


