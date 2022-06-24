#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg)); 
}
int main()
{
	int n = 10;
	chronometry(goo, n);
	chronometry(hoo, 10);
}
