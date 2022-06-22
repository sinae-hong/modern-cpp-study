#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}


// 1. T&& 로 받으면 임의 타입의 lvalue, rvalue 를 복사본 없이, 상수성추가없이
//    받을수 있다.

// 2. 단, rvalue(10) 를 보낼때 받으면서 이름을 가지게 되고 lvalue 가 된다.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// 아래 2줄의 코드는 항상 "rvalue" 로 캐스팅
	static_cast<int&&>(arg); // 항상, int 타입의 rvalue 로 캐스팅
	std::move(arg); // 항상, T 타입의 rvalue 로 캐스팅

	// 아래 캐스팅은 상황에 따라 달라지는 캐스팅
	// chronometry() 의 2번째 인자로
	// lvalue(n)  를 보내면 T=int& 이므로 lvalue 로 캐스팅
	// rvalue(10) 를 보내면 T=int  이므로 rvalue 로 캐스팅
	// => rvalue(10) 를 보내면 받으면서 lvalue 로 변했는데, 그것을 다시 rvalue 로 캐스팅
	// => 흔히, "lvalue 를 lvalue 로 rvalue 를 rvalue 로 캐스팅 한다" 라고 표현합니다
//	f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) ); //이 코드가 위와 동일합니다.(위처럼 캐스팅)
								// T&& 가 아니라 T만 전달하면 됩니다.

	// 꼭 기억할것
	// std::move    : 항상 rvalue 로 캐스팅
	// std::forward : 상황에 따라 다른 캐스팅
	//				 lvalue 를 lvalue 로 rvalue 를 rvalue 로!
}
int main()
{
	int n = 10;
	chronometry(goo, n);	
	chronometry(hoo, 10);	
}
