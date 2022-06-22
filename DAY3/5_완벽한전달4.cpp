// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// 1. int& 와 int&& 버전을 각각 만들어라
// 2. int&& 버전에서는 인자를 forwarding 할때 "rvalue 로 캐스팅" 해서 보내라
/*
template<typename F> void chronometry(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg)); // 필요없는 캐스팅이지만 있어도 됩니다.(컴파일시제거됨)
							   // 이렇게 하면 아래와 구현이 동일해 집니다.
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;
	chronometry(goo, n);	// T=int&		T&&=int&    생성된함수:chronometry(int&)
							// => static_cast<int& >(arg)

	chronometry(hoo, 10);	// T=int		T&&=int&&   생성된함수:chronometry(int&&)
							// => static_cast<int&&>(arg)
}
