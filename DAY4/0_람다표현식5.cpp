// 143 
#include <functional>

int main()
{
	// 람다표현식을 담는 방법
	// 핵심 : 람다표현식의 최종결과는 "임시객체(rvalue)" 입니다.
	auto  f1       = [](int a, int b) { return a + b; }; // ok
	auto& f2       = [](int a, int b) { return a + b; }; // error
	const auto& f3 = [](int a, int b) { return a + b; }; // ok
	auto&& f4      = [](int a, int b) { return a + b; }; // ok

	// 단, 위 표기법중에서는 "f1"이 제일 좋습니다. f1 처럼 사용하세요

	// 람다표현식을 함수 포인터에 담을수 있습니다. - 원리는 뒤에서 설명
	int(*f5)(int, int) = [](int a, int b) { return a + b; }; 
						// class xxx{}; xxx();

	// 람다표현식은 "STL" 의 function 에 담을수 있습니다.
	std::function<int(int,int)> f6 = [](int a, int b) { return a + b; };

	// 핵심 1. 람다표현식은 "auto 변수, 함수포인터, std::function 에 담을수 있습니다."
	// 2. 함수포인터나, function 에 담은 경우, 다른 람다로 바꿀수 있습니다
	f5 = [](int a, int b) { return a - b; }; // ok.. f5 함수 포인터
	f1 = [](int a, int b) { return a - b; }; // error

}


void foo(int(*)(int, int))
{
}
foo( [](int a, int b) { return a + b; } );





