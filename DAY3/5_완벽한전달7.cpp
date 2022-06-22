#include <iostream>

void f0() {}
void f1(int a) {}
void f3(int a, int& r, double d) { r = 200; }

// 완벽한 전달을 사용하려면
// 1. 인자를 받을때는 "T&& - forwarding reference" 사용
// 2. 인자를 다른곳에 보낼때는 "std::forward<T>(arg)" 로 묶어서 전달
// 3. 인자 갯수에 제한을 없게 하려면 "가변인자 템플릿 사용"

template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	f( std::forward<T>(arg)... );
}
int main()
{
	int n = 10;
	chronometry(f0);
	chronometry(f1, 10);
	chronometry(f3, 10, n, 3.4);

	std::cout << n << std::endl; // 200
}
