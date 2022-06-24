#include <iostream>
#include <type_traits>

// static_assert : 조건을 만족하지 못하면,  "컴파일 에러"
// 그런데,          조건을 만족하지 못하면,  에러가 아니라 후보군에서 빠질수 없을까 ?

// 최대공약수를 구하는 함수를 생각해 봅시다.
template<typename T> T gcd(T a, T b)
{
	static_assert( std::is_integral_v<T>, "error, T is not integer");
	return 0;
}
double gcd(double a, double b)
{
	std::cout << "실수 전용 버전" << std::endl;
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
	gcd(3.1f, 5.4f);
}