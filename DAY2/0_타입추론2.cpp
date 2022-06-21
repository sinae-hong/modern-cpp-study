#include <iostream>

// 규칙 1. 값 타입으로 받을때(T arg)
// => 함수 인자가 가지는 "const, volatile, reference" 를 제거하고 
//    타입 결정
template<typename T> void foo(T a)
{
	a = 100;
}
int main()
{
	foo<int>(3.4); // 타입을 직접 전달
				   // 무조건 "T=int"

	// T의 타입을 예측해 보세요
	foo(10); // T = int
	foo(3.4);// T = double

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
//	volatile int k = 0;
	foo(n); // T = int
	foo(c); // T = int
	foo(r); // T = int
	foo(cr);// T = int

	// 주의 ! 인자가 가지는 const 만 제외하고 해야 합니다
	const char* const s = "abcd";
	foo(s);  // T = const char*     => 인자의 const는 제거
			//						=> 가리키는 곳이 const 라는 것은 유지
}

