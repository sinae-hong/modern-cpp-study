#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1. lvalue 받는함수
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2. lvalue/rvalue 
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3. rvalue 받는함수

int main()
{
	int n = 10;
	foo(n);		// 1번 호출, 없으면 2번 호출
	foo(10);	// 3번 호출, 없으면 2번 호출

	int& r1 = n;
	foo(r1);	// 1번 호출, 없으면 2번 호출


	int&& r2 = 10; 
	foo(r2);	// 핵심 !! 몇번 호출할까요 ?  1번.
		
	// int&& r2 = 10 에서
	// int n = 10
	//			데이타 타입		value 속성
	// 10		int				rvalue
	// n		int				lvalue
	// r2		int&&			lvalue

	foo(r2); // r2는 int&& 타입이지만, 이름이 있으므로 lvalue
			// 1번 호출

	foo(static_cast<int&&>(r2)); // 3번 호출되려면, lvalue 인 r2를 "rvalue"로 변경(캐스팅)해야 한다.
						// 이 코드는 타입 캐스팅이 아닙니다.
						// value 속성을 변경하는 casting 입니다.
						// cppreference.com 에서 "static_cast 검색"
						
}
void f1(int&)  {} // int& 를 받겠다는 것이 아니라 int 타입의 "lvalue" 를 받겠다는것
void f1(int&&) {} // int&& 를 받겠다는 것이 아니라 int 타입의 "rvalue" 를 받겠다는것









