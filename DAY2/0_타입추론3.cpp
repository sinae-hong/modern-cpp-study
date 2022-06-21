#include <iostream>

// 규칙 2. 인자가 레퍼런스 일때( T& arg )
// => 인자가 가진 "reference 만 제거" 하고 타입 결정
//    const volatile 은 유지 !
template<typename T> void foo(T& a)
{
	a = 100;
}
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T = int,		  a = int&
	foo(c);  // T = int,		  a = int&   <= 이렇게 결정하면 컴파일에러
										// const 를 non-const 참조로가리킬수없다
			 // T = const int,    a = const int&

	foo(r);  // T = int,		a = int&
	foo(cr); // T = const int	a = const int&
}