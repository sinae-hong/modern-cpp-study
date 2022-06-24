// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 완벽한 전달(perfect forwarding) 이란 ?
// 전달받은 인자를 다른 함수에서 "어떠한 변화도 없이" 그대로 전달하는 것
// "값, 타입, const 여부, value 속성"등 모든 것을 그대로 전달

// 특정 함수의 성능을 측정하는 함수
template<typename F>
void chronometry(F f, int arg)
{
	f(arg);

}
int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
