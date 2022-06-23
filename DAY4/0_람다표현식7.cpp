// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 리턴문이 한개라면 리턴 타입 생략가능(컴파일러가 auto 로 추론)
	auto f2 = [](int a, int b)  { return a + b; };

	// 리턴문이 여러개 라도, 모두 같은 타입이면 생략가능
	auto f3 = [](int a, int b) { if (a == 1) return a;  return  b; };


	// 리턴문이 여러개 인데, 타입이 다르면, 반드시 명시해야 합니다.
	auto f4 = [](double a, int b) -> double { if (a == 1) return a;  return  b; };

	
}

