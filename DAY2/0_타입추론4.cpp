#include <iostream>

// 규칙 1. 값타입으로 받을때
//  함수인자의 "const, volatile, reference"제거후 T결정
//  T의 타입은 결국 a의 타입
template<typename T> void foo(T a)
{
	
}
// 규칙 2. 참조로 받을때
// 함수인자의 "reference" 제거후 T의 타입 결정
// const, volatile은 유지
// T가 결정되면 & 를 붙여서 a의 타입결정
// T가 int 라면 a는 int&

template<typename T> void goo(T& a)
{
	// T 의 타입을 조사하는 방법
	// 1. C++ RTTI 기술 사용
	// => const, volatile,reference 가 출력되지 않습니다. 이렇게 조사하지 마세요
//	std::cout << typeid(T).name() << std::endl;

	// 2. 함수 이름을 출력해서 조사
	// __FUNCTION__ : 함수 이름을 담은 매크로. C++ 표준
	// __FUNCSIG__  : 함수 이름 + 함수 인자 .  C++ 표준아님, MS 전용
	// __PRETTY_FUNCTION__ : 위와 동일 기능, g++ 전용

	//std::cout << __FUNCTION__ << std::endl;
	//std::cout << __FUNCSIG__ << std::endl;

	// 3. godbolt.org 에서 확인하세요..

}


int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T : int
	foo(c);  // T : int
	foo(r);  // T : int 
	foo(cr); // T : int

	goo(n);  // T : int          a : int&
	goo(c);  // T : const int    a : const int&
	goo(r);  // T : int          a : int&
	goo(cr); // T : const int    a : const int&
}