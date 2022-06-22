// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
// main					chronometry						hoo(int&&)
// hoo(10) =============================================> ok
// chronometry(10)===> "int&& arg = 10"
//							hoo(arg) ===================> error. arg는 lvalue
//							hoo(static_cast<int&&>(arg)) ===> ok
template<typename F> void chronometry(F f, int&& arg)
{
	// 원래 이함수를 호출할때 2번째 인자는 rvalue 보냈는데..
	// 인자를 받으면서 lvalue 가 되었다.
	// "chronometry(hoo, 10)" => "int&& arg = 10"
	// 즉, 10 이 arg로 변경
//	f(arg); // error. hoo(int&) 를 찾게 된다.
	f(static_cast<int&&>(arg));
}
int main()
{
	hoo(10); 

	chronometry(hoo, 10);
}
