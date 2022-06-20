// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept 키워드는 2가지 로 사용됩니다.
// 1. 함수 선언 뒤에 붙여서 "예외가 없다"고 알려 줄때 사용
// 2. noexcept(함수호출식) 으로 "함수 호출식"이 예외가 없는지 조사.

void foo()
{
}
void foo(int a, double d) noexcept   // 이 함수는 예외가 없다고 컴파일러에게 알려 주는것
{
}
void goo()  // 예외 가능성이 있다는 의미.
{
}
int main()
{
	// 함수가 예외 가능성이 있는지 조사하는 방법
	bool b1 = noexcept(foo(0, 0.0 )); // 이 순간 foo() 가 호출되는 것은 아님
								// 단지 예외가능성이 있는지 조사
								// foo 선언 뒤에 noexcept가 있는지 조사
	bool b2 = noexcept(goo());
	std::cout << b1 << std::endl; // 1
	std::cout << b2 << std::endl; // 0

	if (noexcept(foo(1, 3.4)))
	{
		// 예외가 없으니, 항상 안전하다.. foo 사용
	}
	else
	{
		// 예외의 가능성이 있다
		// 좀 느리지만, 안전한 다른 함수 사용..
	}
}




