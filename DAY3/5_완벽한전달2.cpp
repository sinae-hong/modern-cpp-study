// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}
// 완벽한 전달을 하려면 
// 1. int& 와 int&& 버전을 각각 제공해야 한다.
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}
int main()
{
	int n = 10;
	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);
	std::cout << n << std::endl;

	hoo(10); // ok
	chronometry(hoo, 10);// error.. 
}
