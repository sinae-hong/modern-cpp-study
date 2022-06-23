// 람다표현식4-1
// 142 page
#include <iostream>

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
			// class xxx { public: int operator()(int a, int b) { return a + b;} };
			// auto f1 = xxx(); 의 모양인데, 결국
			// xxx  f1;         과 동일합니다

	auto f2 = [](int a, int b) { return a + b; };
			// class yyy{}; yyy();  

	// 람다표현식을 보고 컴파일러가 만든 클래스 이름 확인 하는 방법
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;

	// 핵심 1. 모든 람다표현식은 "다른 타입" 입니다
	//      2. 람다표현식으로 초기화된 auto 변수에 다른 람다표현식 담을수 없습니다

	auto f3 = [](int a, int b) { return a + b; };

	f3 = [](int a, int b) { return a + b; }; // error. 
											// f3의 타입과 우변의 타입은 완전히 다릅니다.


}




